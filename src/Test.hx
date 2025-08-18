function run()
{
	// trace inline string
	trace(Hello.getString());

	// trace inline string
	trace(Hello.getString_from_chars());

	// printf const char*
	Hello.passString("hello from haxe äöü !");

	// trace Int from c
	var integer:Int = Hello.getInteger();
	var hex = "0x" + StringTools.hex(integer);
	trace(hex + " : integer from c");

	// trace Int to c
	Hello.passInteger(1337);

	// trace static strings
	trace(Hello.getStringsStatic());
}