import hl.Bytes;

@:hlNative("hello")

class Extern {
	public static function get_greeting():hl.Bytes {
		return null;
	}

	public static function get_greeting_from_chars():hl.Bytes {
		return null;
	}

	public static function greet_me(text:String):Void {
	}
}

class Hello {

	public static function get_greeting():hl.Bytes {
		return Extern.get_greeting();
	}
	
	public static function get_greeting_from_chars():String {
		@:privateAccess
		return String.fromUTF8(Extern.get_greeting_from_chars());
	}
	
	public static function greet_me(text:String) {
		Extern.greet_me(text);
	}
}