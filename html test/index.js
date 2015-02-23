window.onload = function(){
	
	
};
function getMac(){
	
	var macs = mpmack.getMac();
	
	var str = "ERROR. "+macs.msg;
	
	console.log(macs);
	
	if(!macs.err){
		
		str = "";
		
		for(var i in macs.mac ){
			
			str +=i+": "+macs.mac[i]+"\n";
		}
	}
	
	alert(str);
	
	return false;
}