# robosys2020_ros
ロボットシステム学_課題2
  
## 概要
さいころを振れるプログラムです。  
  
## 動画
実際に使用している動画です。  
https://youtu.be/iSXFh4rXUHc  
  
## 必要なもの
Raspberry Pi 4B (Ubuntu 20.04 LTS)  
(動作確認していませんが他のlinux環境でも動くかと思います)  
  
## 動作方法
インストール  
以下のコマンドを実行します。  
rosのワークスペース上で行ってください。  
  
```
$ git clone https://github.com/ventcoursiur/robosys2020_ros.git  
$ cd robosys2020_ros  
$ catkin_make  
$ roscore
```
  
1. パブリッシャの起動  
別の端末でパッケージ内にあるrand_nかrand_tを立ち上げます。  
rand_nはrand()関数を使って、rand_tは乱数テーブルを使って乱数を吐き出します  
例)rand_nを立ち上げる場合  
`$ rosrun robosys2020_ros rand_n`  
  
2. さいころ機能  
さらに別の端末でパブリッシャから受け取った乱数を使ってさいころを振れるプログラムを起動させます。
`$ rosrun robosys2020_ros normal_d`  
すると振るダイスの個数と何面ダイスかを聞かれるので答えますとその結果出ます。  
例）  
```
個数？:2  
面数？:6  
2 + 3 = 5  
```
  
## 余談
TRPGなどでの使用をイメージして作ったのでダイスの面数を指定することが出来ますが、遊ぶシステムによっては6面ダイスしか使わないなんてこともあると思うので、システムに応じて使いやすいノードを今後増やしていけたらいいなと思っています。rosを使えば簡単に組み換えもできて汎用性も高そうだと思ったので。  
  
## ライセンス
GNU General Public License v3.0  
詳細はリポジトリ内にあるCOPYINGを参照してください。  
