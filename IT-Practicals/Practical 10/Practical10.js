var http = require('http');

http.createServer((request,response)=>{
	response.write("Hello World, This is my Node.js server");
	response.end();
})
.listen(10000,()=>console.log('server started at port 10000'));