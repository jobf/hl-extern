function run()
{
	// trace inline string
	trace(Hello.get_greeting());

	// trace inline string
	trace(Hello.get_greeting_from_chars());

	// printf const char*
	Hello.greet_me("hello from haxe!");
}