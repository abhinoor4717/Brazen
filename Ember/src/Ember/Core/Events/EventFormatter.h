#include <spdlog/fmt/bundled/format.h>
#include "Ember/Core/Events/Event.h"

template<>
struct fmt::formatter<Ember::Event> {
    constexpr auto parse(format_parse_context& ctx) -> decltype(ctx.begin()) {
        return ctx.end();
    }

    template <typename FormatContext>
    auto format(const Ember::Event& e, FormatContext& ctx) const -> decltype(ctx.out()) {
        return format_to(ctx.out(), e.ToString());
    }
};