#include <iostream>

#include <cppast/libclang_parser.hpp>
#include <cppast/visitor.hpp> 


void print_ast(const cppast::cpp_file& file)
{
    std::string prefix;
    // visit each entity in the file
    cppast::visit(file, [&](const cppast::cpp_entity& e, cppast::visitor_info info) {
        if (info.event == cppast::visitor_info::container_entity_exit) // exiting an old container
            prefix.pop_back();
        else if (info.event == cppast::visitor_info::container_entity_enter)
        // entering a new container
        {
            std::cout << prefix << "'" << e.name() << "' - " << cppast::to_string(e.kind()) << '\n';
            prefix += "\t";
        }
        else // if (info.event == cppast::visitor_info::leaf_entity) // a non-container entity
            std::cout << prefix << "'" << e.name() << "' - " << cppast::to_string(e.kind()) << '\n';
    });
}


int main()
{
    std::cout <<  "\n";
    std::cout <<  "\n";
    std::cout << "PARSE_FILE =" <<  PARSE_FILE << "\n";
    std::cout <<  "\n";
    std::cout <<  "\n";
    
    using parser_t = cppast::simple_file_parser<cppast::libclang_parser>;
    cppast::cpp_entity_index index;
    parser_t                 parser{type_safe::ref(index)};
    parser_t::config         config;
    config.set_flags(cppast::cpp_standard::cpp_17);


    auto file = parser.parse(PARSE_FILE, config);

    // print_ast(file);
}

