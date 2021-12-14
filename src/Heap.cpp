#include "Graph.cpp"
    
typedef struct {
    string from;
    Vertex * to;
    int path_length;
} ElType;

ElType newElType(string f, Vertex * t, int p) {
    ElType val;
    val.from = f;
    val.to = t;
    val.path_length = p;
    return val;
}

class Heap {

    public:
        ElType data[50];
        int length;

        Heap() {
            length = 0;
        }

        ElType root_node() {
            return data[0];
        }

        ElType last_node() {
            return data[length - 1];
        }

        int left_child_idx(int idx) {
            return (idx * 2) + 1;
        }

        int right_child_idx(int idx) {
            return (idx * 2) + 2;
        }

        int parent_idx(int idx) {
            return (idx - 1) / 2;
        }

        bool has_left_child(int idx) {
            return left_child_idx(idx) < length;
        }

        bool has_right_child(int idx) {
            return right_child_idx(idx) < length;
        }

        bool has_lesser_child(int idx) {
            return 
                (has_left_child(idx) && (data[left_child_idx(idx)].path_length < data[idx].path_length)) 
                || 
                (has_right_child(idx) && (data[right_child_idx(idx)].path_length < data[idx].path_length));
        }

        int calculate_lesser_child_idx(int idx) {
            if (!has_right_child(idx)) {
                return left_child_idx(idx);
            }

            if (data[right_child_idx(idx)].path_length < data[left_child_idx(idx)].path_length) {
                return right_child_idx(idx);
            } else {
                return left_child_idx(idx);
            }
        }

        void insert_data(ElType new_data) {
            int new_node_index;
            ElType temp;

            data[length] = new_data;
            new_node_index = length;
            length++;

            while (new_node_index > 0 && data[new_node_index].path_length < data[parent_idx(new_node_index)].path_length) {
                temp = data[parent_idx(new_node_index)];
                data[parent_idx(new_node_index)] = data[new_node_index];
                data[new_node_index] = temp;

                new_node_index = parent_idx(new_node_index);
            }
        }

        ElType delete_data() {
            ElType temp, val;
            int trickle_node_idx, lesser_child_idx;

            val = root_node();
            data[0] = last_node();
            length--;

            trickle_node_idx = 0;

            while (has_lesser_child(trickle_node_idx)) {
                lesser_child_idx = calculate_lesser_child_idx(trickle_node_idx);

                temp = data[trickle_node_idx];
                data[trickle_node_idx] = data[lesser_child_idx];
                data[lesser_child_idx] = temp;

                trickle_node_idx = lesser_child_idx;
            }
            return val;
        }
};