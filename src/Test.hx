function run()
{
	// trace inline string
	trace(Hello.getGreeting());

	// trace inline string
	trace(Hello.getGreeting_from_chars());

	// printf const char*
	Hello.greetMe("hello from haxe äöü !");

	// trace Int
	var integer:Int = Hello.getInteger();
	var hex = "0x" + StringTools.hex(integer);
	trace(hex + ": integer");
}