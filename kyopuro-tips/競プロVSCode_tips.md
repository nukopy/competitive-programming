# 競プロ My VSCode 覚書

## コンテスト準備編

### Python でコンテストディレクトリの生成

```bash
$ cd /Users/okuwaki/Projects/CLionProjects/atcoder

# Python 3 系が動いていることを確認してから
$ python kyopro_auto_dir.py
# Enter 'contest_name' 'contest_num' 'question' separated by space.
# >>> ABC 139 ABCDEFG
```

### OnlineJudgeTool の使い方

- ログイン

```bash
$ oj login https://atcoder.jp
# USERNAME: ysys13
# PASSWORD: k*********
```

- テストのダウンロード

```bash
$ oj dl https://atcoder.jp/[問題のURL]
```

### エディタの使い

- ビルド：`cmd + shift + B`
- テスト：`cmd + shift + U`（`oj dl` でテストがダウンロードしてあることが前提）
- デバッグ
  - デバッガ起動：`F5`
  - ステップ：`F10`

## sunippets 編

- sunippets の追加: 選択して `(cmd + K) + (cmd + shift + S)`

### 入力系

```txt
inpn
```
