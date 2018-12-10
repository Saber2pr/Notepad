# Notepad

```cpp
Local::getInstance()->connect(this->path_current.toStdString(), input)([=](auto data){
    ui->textEdit->setText(QString::fromStdString(data));
});
```
