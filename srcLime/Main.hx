package;

import Lib;
import lime.app.Application;

class Main extends Application {
	override function onWindowCreate() {
		trace(Lib.get_greeting());
	}
}
