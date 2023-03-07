import 'package:flame/components.dart';
import 'package:flame/game.dart';
import 'package:flame/palette.dart';
import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  SystemChrome.setPreferredOrientations([DeviceOrientation.landscapeLeft])
      .then((_) {
    runApp(GameWidget(game: MyvinayakGame()));
  });
}

class MyvinayakGame extends FlameGame
    with HasTappables, HasDraggables, HasCollisionDetection {
  SpriteComponent vinayak = SpriteComponent();
  SpriteComponent back = SpriteComponent();
  late JoystickComponent joystick;
  @override
  Future<void> onLoad() async {
    await super.onLoad();
    back
      ..sprite = await loadSprite('background.png')
      ..size = size;
    add(back);
    vinayak
      ..sprite = await loadSprite('bunny.png')
      ..size = Vector2.all(200)
      ..position = Vector2(80, 150);
    add(vinayak);
    final knobPaint = BasicPalette.black.withAlpha(200).paint();
    final backgroundpaint = BasicPalette.white.withAlpha(100).paint();
    joystick = JoystickComponent(
      knob: CircleComponent(radius: 10, paint: knobPaint),
      background: CircleComponent(radius: 50, paint: backgroundpaint),
      margin: const EdgeInsets.only(left: 40, bottom: 40),
    );
    add(joystick);
  }

  @override
  void update(double dt) {
    super.update(dt);
    vinayak.position.add(joystick.relativeDelta * 300 * dt);
  }
}
