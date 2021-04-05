if ('WebAssembly' in window) {

  // Step 1: Make a Memory object part of the import object
  var memObj = new WebAssembly.Memory({initial: 256, maximum: 256});
  var importObj = { env: { memory: memObj} };

  // Step 2: Provide the import object in instantiateStreaming
  WebAssembly.instantiateStreaming(fetch('dot.wasm'), importObj)
  .then(result => {
  
    // Step 3: Obtain the addresses of the input arrays
	offset1 = result.instance.exports._getFirstOffset();
	offset2 = result.instance.exports._getSecondOffset();
	
    // Step 4: Create and initialize two typed arrays
	var firstArray = new Uint32Array(memObj.buffer, offset1, 8);
	firstArray.fill(2);
	var secondArray = new Uint32Array(memObj.buffer, offset2, 8);
	secondArray.fill(3);	

    // Step 5: Compute the dot product
	product = result.instance.exports._dot_product();
	document.getElementById('wasm').innerHTML = 
	'Dot product: ' + product;
  });
}