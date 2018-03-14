import WebworkerPromise from 'webworker-promise'
import PromiseFileReader from 'promise-file-reader'

import config from './itkConfig'

import ImageIOWorker from './WebWorkers/ImageIO.worker'

const worker = new ImageIOWorker()
const promiseWorker = new WebworkerPromise(worker)

const readImageFile = (file) => {
  return PromiseFileReader.readAsArrayBuffer(file)
    .then(arrayBuffer => {
      return promiseWorker.postMessage({ operation: 'readImage', name: file.name, type: file.type, data: arrayBuffer, config: config },
        [arrayBuffer])
    })
}

export default readImageFile
