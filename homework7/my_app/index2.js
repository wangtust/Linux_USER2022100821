const express = require('express')
const url = require('url');

const app = express()
// 静态资源在当前目录下

app.use(express.static('.'));

app.get('/', (req, res) => res.send('Hello World from express with back end!'))

// 后端处理代码
app.get('/back-end', (req, res) => {
const query = url.parse(req.url, true).query;
const num1 = parseFloat(query.num1);
const num2 = parseFloat(query.num2);
const result = num1 + num2;

result_str = `${num1} + ${num2} = ${result}`
// 发送HTTP响应
res.send(result_str);
} )

// 绑定服务端口，启动服务器
app.listen(3003, () => console.log('Example app listening on port 3003!'))
