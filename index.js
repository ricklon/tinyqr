var qr = require('qr-image');
var express = require('express');
var im = require('imagemagick');
var fs = require('fs');

var app = express();

app.get('/', function(req, res) {
  var code = qr.image("Voice Labrynth", {
    type: 'svg',
    ec_level: 'L',
    size: 2,
    margin: 0
  });
  res.type('svg');
  code.pipe(res);
  var output = fs.createWriteStream('qr1.svg');
  code.pipe(output);
  im.convert(['qr1.svg', 'qr1.xbm'],
    function(err, stdout) {
      if (err) throw err;
      console.log('stdout:', stdout);
    });
});

app.listen(3000);
