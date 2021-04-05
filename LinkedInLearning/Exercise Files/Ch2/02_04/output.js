if ('WebAssembly' in window) {
	var importObj = {
		env: {
			_print_value: x => 
			document.getElementById('wasm').innerHTML = 
			'Value:' + x
		}
	};

	WebAssembly.instantiateStreaming(fetch('call_func.wasm'), 
	importObj).then(result => result.instance.exports._call_func(9));
}