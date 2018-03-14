import WebworkerPromise from 'webworker-promise'
import PromiseFileReader from 'promise-file-reader'

import config from './itkConfig'

import MeshIOWorker from './WebWorkers/MeshIO.worker'

const worker = new MeshIOWorker()
const promiseWorker = new WebworkerPromise(worker)

const readMeshFile = (file) => {
  return PromiseFileReader.readAsArrayBuffer(file)
    .then(arrayBuffer => {
      return promiseWorker.postMessage(
        {
          operation: 'readMesh',
          name: file.name,
          type: file.type,
          data: arrayBuffer,
          config: config
        },
        [arrayBuffer])
    })
}

export default readMeshFile
