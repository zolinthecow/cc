for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	diff -w <(./1225D < int) <(./brute < int) || break
done
