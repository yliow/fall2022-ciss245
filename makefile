run:
	find . -name 'a.out' -exec rm -f {} \;
	find . -name 'main.exe' -exec rm -f {} \;
	python makedir.py
	git add .; git commit -m"no msg"; git push
