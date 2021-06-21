#
# Copyright (C) 2020 Linux Studio Plugins Project <https://lsp-plug.in/>
#           (C) 2020 Vladimir Sadovnikov <sadko4u@gmail.com>
#
# This file is part of lsp-plugin-fw
#
# lsp-plugin-fw is free software: you can redistribute it and/or modify
# it under the terms of the GNU Lesser General Public License as published by
# the Free Software Foundation, either version 3 of the License, or
# any later version.
#
# lsp-plugin-fw is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU Lesser General Public License for more details.
#
# You should have received a copy of the GNU Lesser General Public License
# along with lsp-plugin-fw.  If not, see <https://www.gnu.org/licenses/>.
#

# Specify plugin package version
PLUGIN_PACKAGE_VERSION                  := 0.0.1

# Specify description of plugin dependency
LSP_PLUGINS_COMP_DELAY_VERSION          := 1.0.3
LSP_PLUGINS_COMP_DELAY_NAME             := lsp-plugins-comp-delay
LSP_PLUGINS_COMP_DELAY_TYPE             := plug
LSP_PLUGINS_COMP_DELAY_URL              := git@github.com:sadko4u/$(LSP_PLUGINS_COMP_DELAY_NAME).git

# Specify description of plugin dependency
LSP_PLUGINS_PHASE_DETECTOR_VERSION      := 1.0.0
LSP_PLUGINS_PHASE_DETECTOR_NAME         := lsp-plugins-phase-detector
LSP_PLUGINS_PHASE_DETECTOR_TYPE         := plug
LSP_PLUGINS_PHASE_DETECTOR_URL          := git@github.com:sadko4u/$(LSP_PLUGINS_PHASE_DETECTOR_NAME).git

# List of all plugin dependencies
PLUGIN_DEPENDENCIES = \
  LSP_PLUGINS_COMP_DELAY \
  LSP_PLUGINS_PHASE_DETECTOR
