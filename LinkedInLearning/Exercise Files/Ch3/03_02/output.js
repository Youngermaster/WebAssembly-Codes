if ('WebAssembly' in window) {

  // Step 1: Create a memory object
  var memObj = new WebAssembly.Memory({initial: 256, maximum: 256});

  // Step 2: Make the memory object part of the import object and pass the import object to instantiateStreaming
  var importObj = { env: { memory: memObj} };
  WebAssembly.instantiateStreaming(fetch('quicksort.wasm'), importObj)
  .then(result => {

    // Step 3: Obtain the address of the WebAssembly array
	offset = result.instance.exports._getOffset();

    // Step 4: Create and initialize a typed array
	var i;
	var mem = new Uint32Array(memObj.buffer, offset, 16);
	for(i=0; i<16; i++) {
		mem[i] = Math.floor(16 * Math.random());
	}

    // Step 5: Call the quicksort function to sort the array
	result.instance.exports._quicksort(0, 15);
	
	resultString = "";
	for(i=0; i<16; i++) {
		resultString += ' ' + mem[i];
	}
	document.getElementById('wasm').innerHTML = 
	'Output: ' + resultString;
  });
}







