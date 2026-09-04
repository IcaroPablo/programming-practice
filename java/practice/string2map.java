private static Map<String, Object> parseMapFrom(String mapString) {
    if (Objects.isNull(mapString)) return new HashMap<>();

    var pairs = mapString.replaceAll("^.|.$", "").split("(?<!\\{[^{}]*), (?![^{]*})");

    return Arrays.stream(pairs)
        .map(pair -> pair.split("=", 2))
        .collect(
            Collectors.toMap(
                keyValue -> keyValue[0],
                keyValue -> keyValue[1].startsWith("{") ? parseMapFrom(keyValue[1]) : keyValue[1]));
}
