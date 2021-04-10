/*
 * Copyright (C) 2021 Linux Studio Plugins Project <https://lsp-plug.in/>
 *           (C) 2021 Vladimir Sadovnikov <sadko4u@gmail.com>
 *
 * This file is part of lsp-plugin-fw
 * Created on: 10 апр. 2021 г.
 *
 * lsp-plugin-fw is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * lsp-plugin-fw is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with lsp-plugin-fw. If not, see <https://www.gnu.org/licenses/>.
 */

#include <private/ui/xml/SetNode.h>
#include <private/ui/xml/NodeFactory.h>

namespace lsp
{
    namespace ui
    {
        namespace xml
        {
            //-----------------------------------------------------------------
            NODE_FACTORY_IMPL_START(SetNode)
                if (!name->equals_ascii("ui:set"))
                    return STATUS_NOT_FOUND;

                Node *node = new SetNode(context);
                if (node == NULL)
                    return STATUS_NO_MEM;

                status_t res = node->init(atts);
                if (res != STATUS_OK)
                {
                    delete node;
                    return res;
                }

                *child  = node;
                return STATUS_OK;
            NODE_FACTORY_IMPL_END(SetNode)

            //-----------------------------------------------------------------
            SetNode::SetNode(UIContext *ctx): Node(ctx)
            {
            }

            status_t SetNode::init(const LSPString * const *atts)
            {
                status_t res;
                size_t flags = 0;
                LSPString v_name;
                expr::value_t v_value;
                expr::init_value(&v_value);

                for ( ; *atts != NULL; atts += 2)
                {
                    const LSPString *name   = atts[0];
                    const LSPString *value  = atts[1];

                    if ((name == NULL) || (value == NULL))
                        continue;

                    if (name->equals_ascii("id"))
                    {
                        if ((res = pContext->eval_string(&v_name, value)) != STATUS_OK)
                            return res;
                        flags      |= 1;
                    }
                    else if (name->equals_ascii("value"))
                    {
                        if ((res = pContext->evaluate(&v_value, value)) != STATUS_OK)
                            return res;
                        flags      |= 2;
                    }
                    else
                    {
                        lsp_error("Unknown attribute: %s", name->get_utf8());
                        return STATUS_CORRUPTED;
                    }
                }

                if (flags != 3)
                {
                    lsp_error("Not all attributes are set");
                    return STATUS_CORRUPTED;
                }

                // Set variable and destroy value
                res = pContext->vars()->set(&v_name, &v_value);
                expr::destroy_value(&v_value);
                return res;
            }

        }
    }
}
