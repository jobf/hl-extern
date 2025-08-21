/**
 * bindings for c/lib/hello.c
 */
@:hlNative("hello") extern class C 
{
	static function get_string():hl.Bytes;

	static function get_string_from_chars():hl.Bytes;

	static function pass_string(text:String):Void;

	static function get_integer():Int;

	static function pass_integer(int:Int):Void;

	static function get_strings_static():hl.NativeArray<hl.Bytes>;

	// work in progress
	// static function get_strings_dynamic(text:String, repeats:Int):hl.NativeArray<hl.Bytes>;
}

/**
 * haxe interface for using the C bindings
 */
class Hello 
{
	public static function getString():String
	{
		var bytes = C.get_string();
		@:privateAccess
		return String.fromUTF8(bytes);
	}

	public static function getString_from_chars():String 
	{
		var bytes = C.get_string_from_chars();
		@:privateAccess
		return String.fromUTF8(bytes);
	}

	public static function passString(text:String) 
	{
		C.pass_string(text);
	}

	public static function getInteger() {
		return C.get_integer();
	}

	public static function passInteger(integer:Int) {
		C.pass_integer(integer);
	}

	public static function getStringsStatic():Array<String> {
		var dstrings:hl.NativeArray<hl.Bytes> = C.get_strings_static();
		@:privateAccess
		var strings = [for(d in dstrings) String.fromUTF8(d)];
		return strings;
	}

	// work in progress
	// public static function getStringsDynamic(text:String, repeats:Int):Array<String> {
	// 	var dstrings:hl.NativeArray<hl.Bytes> = C.get_strings_dynamic(text, repeats);
	// 	@:privateAccess
	// 	var strings = [for(d in dstrings) String.fromUTF8(d)];
	// 	return strings;
	// }
}
