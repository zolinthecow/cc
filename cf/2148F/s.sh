for ((i = 1; ; ++i)); do
	echo $i
	./gen $i > int
	./2148F < int > /dev/null
	# diff -w <(./2148F < int) <(./brute < int) || break
done
