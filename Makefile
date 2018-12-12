
# Copyright 2018 Thomas E. Vaughan.
# See LICENSE.

relations.png : relations.dot
	dot -T png -o relations.png relations.dot

.PHONY: clean

clean:
	rm -fv relations.png

