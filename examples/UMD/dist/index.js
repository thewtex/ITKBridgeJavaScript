let readerWebWorker = null
let meshToPolyDataWebWorker = null

function processFile(event) {
  const outputTextArea = document.querySelector("textarea");
  outputTextArea.textContent = "Loading...";

  const dataTransfer = event.dataTransfer;
  const files = event.target.files || dataTransfer.files;

  return itk.readFile(readerWebWorker, files[0])
    .then(function({ image, mesh, polyData, webWorker }) {
      readerWebWorker = webWorker
      const imageOrMeshOrPolyData = image || mesh || polyData;

      function replacer(key, value) {
        if (!!value && value.byteLength !== undefined) {
          return String(value.slice(0, 6)) + "...";
        }
        return value;
      }
      outputTextArea.textContent = JSON.stringify(imageOrMeshOrPolyData, replacer, 4);

      const renderingElement = document.getElementById('rendering')
      if (image) {
        const vtkImage = itkVtkViewer.utils.vtkITKHelper.convertItkToVtkImage(image)
        const use2D = image.imageType.dimension === 2
        const viewer = itkVtkViewer.createViewer(renderingElement, { image: vtkImage, use2D })
        viewer.setUserInterfaceCollapsed(true)
      } else if(polyData) {
        const polyDataObject = itkVtkViewer.utils.vtk(polyData)
        viewer = itkVtkViewer.createViewer(renderingElement, { geometries: [polyDataObject] })
        viewer.setUserInterfaceCollapsed(true)
      } else if(mesh) {
        console.log(mesh)
        const pipeline = 'MeshToPolyData'
        const args = ['mesh.vtk.json', 'mesh.vtk.written.json']
        const desiredOutputs = [
          { path: args[1], type: itk.IOTypes.vtkPolyData }
        ]
        const inputs = [
          { path: args[0], type: itk.IOTypes.Mesh, data: mesh }
        ]
        itk.runPipelineBrowser(meshToPolyDataWebWorker, pipeline, args, desiredOutputs, inputs)
          .then(({ outputs, webWorker }) => {
          meshToPolyDataWebWorke = webWorker
          const polyDataObject = itkVtkViewer.utils.vtk(outputs[0].data)
          console.log(polyDataObject)
          viewer = itkVtkViewer.createViewer(renderingElement, { geometries: [polyDataObject] })
          viewer.setUserInterfaceCollapsed(true)
          })
      }
    });
}
