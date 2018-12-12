# note.exe

```cpp
Local::getInstance()->connect(this->path_current.toStdString(), input)([=](auto data){
    ui->textEdit->setText(QString::fromStdString(data));
});
```

![loadingImage...](https://github.com/Saber2pr/MyWeb/raw/master/resource/note.jpg)