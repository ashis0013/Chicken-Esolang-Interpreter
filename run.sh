File=ChickenKt.class
if [ -f "$File" ]; then
	kotlin ChickenKt $1 $2
else
	kotlinc Extensions.kt
	kotlinc -cp . Chicken.kt
	kotlin ChickenKt $1 $2
fi
