// const fs = require('fs');
// // const {WASI} = require('wasi');
// // const { WASI } = internalBinding('wasi');
// const express = require('express')
// const app = express()

// express.static.mime.define({'application/wasm': ['wasm']});

// app.use(express.static('public', {
//     setHeaders:(res,path,stat)=>{
//         if (path.endsWith('.wasm')) {
//             res.set('Content-Type', 'applicatio/wasm')
//         }
//     }
// }))
// app.listen(4444,()=>console.log('server is running on host 4444'))

// const wasi = new WASI({
//   args: process.argv,
//   env: process.env,
//   preopens: {
//     '/sandbox': '/some/real/path/that/wasm/can/access'
//   }
// });
// const importObject = { wasi_snapshot_preview1: wasi.wasiImport };

// (async function () {
// const wasm = await WebAssembly.compile(fs.readFileSync('./demo.wasm'));
// const instance = await WebAssembly.instantiate(wasm, importObject);
  
// wasi.start(instance);
// })()
const fs = require('fs')

async function main() {
  // Read the wasm file.
  const buf = fs.readFileSync('./demo.wasm')

  // Create a WebAssembly instance from the wasm.
  const res = await WebAssembly.instantiate(buf, {})
  
  // Get the function to call.
  const { addTwoInts } = res.instance.exports
  
  // Call the function.
  const a = 38, b = 4
  const result = addTwoInts(a, b)
  console.log(`${a} + ${b} =  ${result}`)
}

main().then(() => console.log('Done'))

process.exit(1)