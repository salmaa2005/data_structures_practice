return {
  "mfussenegger/nvim-lint",
  event = { "BufReadPre", "BufNewFile" },
  opts = {
    linters_by_ft = {
      c = { "betty_style", "betty_doc" },
      cpp = { "betty_style", "betty_doc" },
    },
    linters = {
      betty_style = require("linters.betty_style"),
      betty_doc = require("linters.betty_doc"),
    },
  },
}
