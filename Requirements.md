# Requirements: Temperature and Humidity Logger

## 概要 (Overview)
Raspberry Pi を用いて温度・湿度を定期的に計測し、ログとして記録・可視化するシステム。

## 機能要件 (Functional Requirements)

1. **計測 (Sensing)**
   - 温度と湿度を一定間隔（1分ごと）で取得する

2. **ログ記録 (Logging)**
   - 取得した値をログとして書き溜める

3. **統計計算 (Statistics)**
   - 書き溜めたデータから統計量（平均・最大・最小など）を計算する

4. **表示 (Display)**
   - LCD に現在の温度・湿度を常時表示する

5. **アクチュエータ制御 (Actuator Control)**
   - 温度が高いとファンが回る
   - 温度が高いと LED が点灯する
   - ON/OFF の切り替えにはヒステリシス設計を採用する（閾値付近でのチャタリング防止）

## 非機能要件 (Non-functional Requirements)

- ハードウェア依存部分（センサー、LCD、アクチュエータ）は抽象化し、実機がなくてもモックでテスト可能にする
- センサーや保存先（CSV / DB）は将来的に差し替え可能な設計にする

## 未確定事項 (TBD)

- 使用センサーの型番（DHT22 / BME280 など）
- ログの保存形式（CSV / SQLite）
- ファン・LED の ON/OFF 閾値とヒステリシス幅