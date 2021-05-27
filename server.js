const express = require('express')
const app = express()
const fs = require('fs')

express.static.mime.define({'application/wasm': ['wasm']});

app.use(express.static('./dist'));

app.use(express.static('public', {
    setHeaders:(res,path,stat)=>{
        if (path.endsWith('.wasm')) {
            res.set('Content-Type', 'applicatio/wasm')
        }
    }
}))
app.listen(3333,()=>console.log('server is running on host 3333'))
