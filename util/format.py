BOX_WIDTH=9
BOXES_PER_ROW=[12, 12, 12, 14, 6]
OUTPATH = "output.txt"
GAP = 26

ASCII_ROWS = [
  "//┌────────┬────────┬────────┬────────┬────────┬────────┐                          ┌────────┬────────┬────────┬────────┬────────┬────────┐",
  "//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤",
  "//├────────┼────────┼────────┼────────┼────────┼────────┤                          ├────────┼────────┼────────┼────────┼────────┼────────┤",
  "//├────────┼────────┼────────┼────────┼────────┼────────┼────────┐        ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤",
  "//└────────┴────────┴────────┴───┬────┴───┬────┴───┬────┴───┬────┘        └───┬────┴───┬────┴───┬────┴───┬────┴────────┴────────┴────────┘",
                                "// └────────┴────────┴────────┘                 └────────┴────────┴────────┘"
]

def get_gap_spaces(num_boxes: int) -> str:
    # if 12 then just return gap * " "
    if num_boxes == 12:
        return (GAP + 1)* " "
    if num_boxes == 14:
        # return 9 * " "
        return (GAP - 2 * BOX_WIDTH + 1) * " "
    return 18 * " "

def left_align_kc(kc: str) -> str:
    # NOTE: kc here is just the raw keycode
    # without the trailing comma
    # so we need to remember to add the trailing comma back in
    l = len(kc)
    has_traiing_comma = kc[-1] == ','
    req_spaces = BOX_WIDTH - l - 1

    if has_traiing_comma:
        req_spaces -= 1
        return kc + ' ' * req_spaces

    return kc + ',' + ' ' * req_spaces

def as_str(x: list[str]) -> str:
    return "".join(x)

def get_formatted_line(row: int, line: list[str]) -> str:
    num_boxes = BOXES_PER_ROW[row]
    split_width = num_boxes // 2

    formatted =  list(map(left_align_kc, line))

    spaces = get_gap_spaces(num_boxes)
    left, right = formatted[:split_width], formatted[split_width:]
    return as_str(left) + spaces + as_str(right)


# rows -> keys
# [KC_1, KC_2 ...]
# [KC_3, KC_4 ...]
def get_kb_format(cur_layer: list[list[str]]) -> list[str]:
    output = []
    for (row, line) in enumerate(cur_layer):
        formatted_line = get_formatted_line(row, line)
        output.append(formatted_line)
    return output

# NOTE: returns a  list of layers -> rows -> keys
def get_kb(layers: list[str]) -> list[list[list[str]]]:
    output = []
    for line in layers:
        row = []
        cur_line: list[str] = line.split(', ')
        for num_boxes in BOXES_PER_ROW:
            row.append(cur_line[:num_boxes])
            cur_line = cur_line[num_boxes:]
        output.append(row)
    return output

def insert_outline(layer: list[str]) -> list[str]:
    output = []
    for index, row in enumerate(layer):
        num_spaces = 35 if index == len(layer) - 1 else 4
        output.append(" " + ASCII_ROWS[index])
        output.append((num_spaces) * " " + row)

    output.append(31 * " " + ASCII_ROWS[-1])
    print(output)
    return output

if __name__ == '__main__':
    input= open('input.txt','r').read().splitlines()
    kb = get_kb(input)
    lines: list[str] = []
    for k in kb:
        base = get_kb_format(k)
        formatted = insert_outline(base)
        lines.append("\n".join(formatted))
    output = open(OUTPATH,'w')
    output.write("\n".join((lines)))
