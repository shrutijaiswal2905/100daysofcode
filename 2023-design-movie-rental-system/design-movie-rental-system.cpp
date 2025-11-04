#include <vector>
#include <unordered_map>
#include <set>
#include <algorithm>

class MovieRentingSystem {
private:
    // Store unrented movies: movie_id -> sorted set of (price, shop_id)
    std::unordered_map<int, std::set<std::pair<int, int>>> unrented;
  
    // Store price lookup: (shop_id, movie_id) -> price
    std::map<std::pair<int, int>, int> shopAndMovieToPrice;
  
    // Store currently rented movies: sorted set of (price, shop_id, movie_id)
    std::set<std::tuple<int, int, int>> rented;

public:
    /**
     * Initialize the movie renting system.
     * @param n Number of shops
     * @param entries List of [shop, movie, price] entries
     */
    MovieRentingSystem(int n, std::vector<std::vector<int>>& entries) {
        // Process initial entries
        for (const auto& entry : entries) {
            int shop = entry[0];
            int movie = entry[1];
            int price = entry[2];
          
            // Add to unrented inventory
            unrented[movie].insert({price, shop});
          
            // Store price for quick lookup
            shopAndMovieToPrice[{shop, movie}] = price;
        }
    }
  
    /**
     * Search for the 5 cheapest shops that have an unrented copy of the given movie.
     * @param movie The movie ID to search for
     * @return List of up to 5 shop IDs with cheapest prices
     */
    std::vector<int> search(int movie) {
        std::vector<int> result;
      
        // Check if the movie exists in unrented inventory
        if (unrented.find(movie) != unrented.end()) {
            // Get up to 5 shops with the cheapest prices
            int count = 0;
            for (const auto& [price, shop] : unrented[movie]) {
                if (count >= 5) break;
                result.push_back(shop);
                count++;
            }
        }
      
        return result;
    }
  
    /**
     * Rent a movie from a specific shop.
     * @param shop The shop ID
     * @param movie The movie ID to rent
     */
    void rent(int shop, int movie) {
        // Get the price for this shop-movie combination
        int price = shopAndMovieToPrice[{shop, movie}];
      
        // Remove from unrented inventory
        unrented[movie].erase({price, shop});
      
        // Add to rented inventory
        rented.insert({price, shop, movie});
    }
  
    /**
     * Return a rented movie to a specific shop.
     * @param shop The shop ID
     * @param movie The movie ID to return
     */
    void drop(int shop, int movie) {
        // Get the price for this shop-movie combination
        int price = shopAndMovieToPrice[{shop, movie}];
      
        // Add back to unrented inventory
        unrented[movie].insert({price, shop});
      
        // Remove from rented inventory
        rented.erase({price, shop, movie});
    }
  
    /**
     * Get the 5 cheapest rented movies.
     * @return List of up to 5 [shop_id, movie_id] pairs
     */
    std::vector<std::vector<int>> report() {
        std::vector<std::vector<int>> result;
      
        // Get up to 5 cheapest rented movies
        int count = 0;
        for (const auto& [price, shop, movie] : rented) {
            if (count >= 5) break;
            result.push_back({shop, movie});
            count++;
        }
      
        return result;
    }
};
