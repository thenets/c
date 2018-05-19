/*jshint esversion: 6 */

function swap (x, y) {
    [elements[y], elements[x]] = [elements[x], elements[y]];
}

function debug (debug_content) {
    document.getElementById('debug').innerHTML =
        document.getElementById('debug').innerHTML + '<br>' + JSON.stringify(debug_content);
}