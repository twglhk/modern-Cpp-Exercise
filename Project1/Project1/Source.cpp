#define ACTOR_WIDTH 100
#define ACTOR_SPEED 200

class World
{
	float width, height;

public:
	float getWidth() { return width; }
};

struct Position
{
	float x, y;
};

struct Velocity
{
	float x, y;
};

World world;
Position position;
Velocity velocity;

void update(float deltaTime)
{
	move(deltaTime);
	if (isTurnLeft()) { turnLeft(); }
	if (isTurnRight()) { turnRight(); }
}

// 이동
void move(float deltatime)
{
	position.x += velocity.x * deltatime;
}

// 오른쪽 끝 구하기
float rightBorder()
{
	return world.getWidth() - (ACTOR_WIDTH / 2.0f);
}

// 왼쪽 끝 구하기
float leftBorder()
{
	return (ACTOR_WIDTH / 2.0f);
}

// 왼쪽으로 튕기는지 확인
float isTurnLeft() 
{
	return position.x > rightBorder();
}

// 오른쪽으로 튕기는지 확인
float isTurnRight()
{
	return position.x < leftBorder();
}

// 왼쪽으로 튕김
void turnLeft()
{
	position.x = rightBorder();
	velocity.x = -ACTOR_SPEED;
}

// 오른쪽으로 튕김
void turnRight()
{
	position.x = leftBorder();
	velocity.x = ACTOR_SPEED;
}