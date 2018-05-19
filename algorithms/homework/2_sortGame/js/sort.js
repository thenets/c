/*jshint esversion: 6 */

function generateRandomArray (nElements, maxValue=100) {
    var array = [];
    
    for (index = 0; index < nElements; index++) {
        array[index] = Math.floor(Math.random() * maxValue);
        
    }
    
    return array;
}

function bubbleSortArray (original_array_data) {
    var output = [];
    
    array_data = original_array_data.slice(0);
    output.push(array_data.slice(0));

    var hasMove=1;
    var nIterations=0, nMoves=0;
	while(hasMove){
        hasMove=0;
		for (i=1; i<array_data.length; i++) {
			if(array_data[i][1] < array_data[i-1][1]) {
				higher = array_data[i];
				
				tmp = array_data[i-1];
				array_data[i-1] = array_data[i];
				array_data[i] = tmp;
				
				nMoves++;
                hasMove=1;

                // Append new array state
                output.push(array_data.slice(0));
			}
			nIterations++;
		}
	}
    
    return output;
}