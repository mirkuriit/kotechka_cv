### Сборка:  

```shell
mkdir build && cd build && cmake .. && make
```

Оригинальное изображение:  
<img src="meow.jpg" alt="Описание" width="300">

### Первый пример:  
```shell
./program --input "../meow.jpg" --out "../out_gaus.jpg" --kernel "../gaussian_blur.txt"
```
Результат:  
<img src="out_gaus.jpg" alt="Описание" width="300">


### Второй пример:  
```shell
 ./program --input "../meow.jpg" --out "../out_boke.jpg" --kernel "../boke.txt"
 ```

Результат:  
<img src="out_boke.jpg" alt="Описание" width="300">

### Третий пример:
```shell
./program --input "../meow.jpg" --out "../out_beautiful.jpg" --kernel "../beautiful.txt"
```
<img src="out_beautiful.jpg" alt="Описание" width="300">