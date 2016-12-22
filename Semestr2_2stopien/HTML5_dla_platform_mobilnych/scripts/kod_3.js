addEventListener('message',onMessage, false);


function onMessage(evt)
{
	console.log("Recieved message " + evt.data);
    var file = evt.data;
    var reader = new FileReaderSync();

    console.log("Reading");
    // Read the contents of the image file as a data URL
	var out = reader.readAsDataURL(file);
    
    postMessage(out);
}

