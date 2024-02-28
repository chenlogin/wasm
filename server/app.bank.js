// server.js  
const Koa = require('koa');  
const serve = require('koa-static');  
const path = require('path');  
const app = new Koa();  
  
// 设置静态资源目录  
app.use(serve(path.join(__dirname, '../dist')));  
  
app.listen(3000, () => {  
  console.log('Server running on http://localhost:3000');  
});