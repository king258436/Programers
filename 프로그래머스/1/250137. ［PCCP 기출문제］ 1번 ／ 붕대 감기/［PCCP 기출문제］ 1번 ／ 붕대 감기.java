class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int ori_health = health;
        int con_sec=0; //연속 붕대 감는 시간
        int len = attacks[attacks.length-1][0];
        int point=0;
        for(int sec=1;sec<=len;sec++){
            if(attacks[point][0]==sec){
                health-=attacks[point][1];
                con_sec=0;
                point++;
                if(health<=0){
                    return -1;
                }
            }
            else{
                if(health<ori_health){// 체력이 최댓값 보다 작을때
                    con_sec++;// 연속회복 횟수 증가
                    health+=bandage[1];
                    if(con_sec==bandage[0]){
                        con_sec=0;
                        health+=bandage[2];
                    }
                    if(health>ori_health){
                        health=ori_health;
                    }
                }
            }
        }
        return health;
    }
}