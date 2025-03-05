public class ProgSports {
    public static void main(String[] args) {
        LesSports sports = new LesSports();

        sports.sportAdd(new Sport(1, "Golf"));
        sports.sportAdd(new Sport(2, "Msuculation"));
        sports.sportAdd(new Sport(3, "Tir à l'arc"));

        sports.sportAdd(new SportCo(4, "Foot", 11));
        sports.sportAdd(new SportCo(5, "VoleyBall", 6));
        sports.sportAdd(new SportCo(6, "Basket", 5));

        sports.sportDisplay();
    }
}