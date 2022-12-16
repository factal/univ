#include <stdio.h>
#include <stdlib.h>
#define N 100

void ReadDataFile(double *Data){
  int i,scannum;
  
  FILE *file = fopen("d111.txt","r");
  if (file == NULL) {  /* ファイルを正しく開けなかった場合 */
    fprintf(stderr, "cannot open file\n");
    exit(1);  /* 強制終了 */
  }
  for (i = 0; i < N; i++) {
    scannum = fscanf(file, "%lf", &Data[i]);
    if(scannum != 1){
    	fprintf(stderr,"cannot read file\n");
    	exit(1);
    }
  }
  
  fclose(file);  /* ファイルを閉じる */
}

int SequentialSearch(double *Data, double key){
  int i;
  for (i = 0; i < N; i++) {
    if (Data[i] == key) {
      return i;
    }
  }
  if (i < N) {
    printf("found at %d\n", i);
  } else {
    printf("not found\n");
  }
  return -1;
}

int main(void){
  int i;
  double Data[N], key;

  /* ファイルからのデータの読み込み */
  ReadDataFile(Data);
  /* これ以降，Dataは要素数Nの配列として扱える */

  /* 検索キーを入力してもらう */
  printf("key: ");
  scanf("%lf", &key);

  /* 逐次探索法の実行 */
  i = SequentialSearch(Data, key);

  /* 探索結果の出力 */
  return 0;
}