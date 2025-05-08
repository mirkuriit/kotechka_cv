### Сборка:  

```shell
mkdir build && cd build && cmake .. && make
```

Оригинальное изображение:  
<img src="meow.jpg" alt="Описание" width="300">

### Первый пример:  
```shell
./program --input "../meow.jpg" --out "../3x3.jpg"  ---kernel_size 3
```
Результат:  
<img src="3x3.jpg" alt="Описание" width="300">


### Второй пример:  
```shell
./program --input "../meow.jpg" --out "../5x5.jpg"  ---kernel_size 5
 ```

Результат:  
<img src="5x5.jpg" alt="Описание" width="300">

### Третий пример:
```shell
./program --input "../meow.jpg" --out "../100x100.jpg"  ---kernel_size 100
```
<img src="100x100.jpg" alt="Описание" width="300">