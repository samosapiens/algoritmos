// Dependencias
var fs = require('fs');
var http = require('http');
var plotly = require('plotly')("samosapiens", "J1v8KHIXFg91x9Pp0Eok")

// Create server
var server = http.createServer(function(request, response) { 

    // Read HTML file
    fs.readFile('./julia.html', function (err, html) {

        // Error loading file
        if (err) throw err;     
        
        // Show HTML file
        response.writeHeader(200, {"Content-Type": "text/html"});  
        response.write(html);  
        response.end();
        
    }); 

});

// Listen port 8080
const PORT=8080; 
server.listen(PORT);
console.log('Server running at http://127.0.0.1:' + PORT + '/');