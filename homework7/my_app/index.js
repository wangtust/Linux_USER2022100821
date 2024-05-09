const express = require('express')

// 得到server（服务器）实例
const app = express()

// 绑定服务器接受请求事件，并且添加处理回调函数
app.get('/', (req, res) => res.send('Hello World from express!'))

// 绑定服务端口，启动服务器
app.listen(3001, () => console.log('Example app listening on port 3001!'))
