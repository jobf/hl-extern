import lime.app.Application;

class Main extends Application 
{
	override function onWindowCreate() 
	{
		// trace inline string
		trace(Hello.get_greeting());
	
		// trace const char*
		trace(Hello.get_greeting_from_chars());
	}
}
