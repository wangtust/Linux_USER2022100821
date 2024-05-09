const express = require('express')
const url = require('url');
const {exec} = require('child_process');
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

app.get('/ls', (req, res) => {
// 输出当前目录（不一定是代码所在的目录）下的文件和文件夹
exec('ls -l', (err, stdout, stderr) => {
    if(err) {
        console.log(err);
        return;
    }
    console.log(`stdout: ${stdout}`);
   // console.log(`stderr: ${stderr}`);
    res.send(`stdout: ${stdout}`);
});

} )
// 绑定服务端口，启动服务器
app.listen(3004, () => console.log('Example app listening on port 3004!'))
