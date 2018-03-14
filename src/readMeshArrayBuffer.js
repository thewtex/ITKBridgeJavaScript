import WebworkerPromise from 'webworker-promise'

import config from './itkConfig'

import MeshIOWorker from './WebWorkers/MeshIO.worker.js'

const worker = new MeshIOWorker()
const promiseWorker = new WebworkerPromise(worker)

const readMeshArrayBuffer = (arrayBuffer, fileName, mimeType) => {
  return promiseWorker.postMessage(
    {
      operation: 'readMesh',
      name: fileName,
      type: mimeType,
      data: arrayBuffer,
      config: config,
      origin: document.location.origin
    },
    [arrayBuffer])
}

export default readMeshArrayBuffer
