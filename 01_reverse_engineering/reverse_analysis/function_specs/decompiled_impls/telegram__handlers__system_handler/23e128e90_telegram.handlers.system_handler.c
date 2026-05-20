/* ===== 23e128e90 telegram.handlers.system_handler:20 ===== */
/* ghidra_name=FUN_23e128e90 entry=23e128e90 size=3566 */

longlong * FUN_23e128e90(longlong param_1)

{
  code *pcVar1;
  longlong *plVar2;
  undefined8 *puVar3;
  longlong *plVar4;
  int iVar5;
  int iVar6;
  longlong lVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  longlong lVar13;
  undefined8 uVar14;
  code *pcVar15;
  code *pcVar16;
  undefined4 uVar17;
  longlong lVar18;
  code *pcVar19;
  code *pcVar20;
  code *pcVar21;
  code *local_b0;
  code *local_a8;
  undefined8 uStack_a0;
  undefined1 local_98 [16];
  code *local_88 [2];
  code *local_78;
  longlong *plStack_70;
  code *local_68;
  
  plVar9 = DAT_23eeaae80;
  if (DAT_23eeaae80 == (longlong *)0x0) {
LAB_23e128ed2:
    DAT_23eeaae80 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeaae78,DAT_23eeaae98,8);
  }
  else {
    lVar7 = *DAT_23eeaae80;
    if (1 < lVar7) {
      *DAT_23eeaae80 = lVar7 + -1;
      goto LAB_23e128ed2;
    }
    if (DAT_23eeaae80[2] != 0) {
      *DAT_23eeaae80 = lVar7 + -1;
      if (lVar7 + -1 == 0) {
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      goto LAB_23e128ed2;
    }
  }
  plVar2 = DAT_23eeaae80;
  lVar7 = *(longlong *)(param_1 + 0x38);
  plVar9 = DAT_23eeaae80 + 9;
  lVar13 = *(longlong *)(lVar7 + 8);
  DAT_23eeaae80[0xf] = lVar13;
  *(longlong **)(lVar7 + 8) = plVar9;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar2[0xe] != 0)))) {
    plVar9 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar2[0xe] + 0x10) = plVar9;
    if (plVar9 != (longlong *)0x0) {
      *plVar9 = *plVar9 + 1;
    }
  }
  *plVar2 = *plVar2 + 1;
  *(undefined4 *)(plVar2 + 8) = 0;
  lVar7 = FUN_23e8ffa20();
  if (lVar7 == 0) {
    uVar17 = 0x18;
    FUN_23e915740(param_1,&local_78,DAT_23eea85e8);
    pcVar21 = local_68;
    pcVar16 = local_78;
    plVar9 = plStack_70;
  }
  else {
    plVar8 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23eea85f0);
    if (plVar8 == (longlong *)0x0) {
LAB_23e129120:
      pcVar21 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar17 = 0x18;
      pcVar16 = *(code **)(param_1 + 0x60);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      plVar9 = *(longlong **)(param_1 + 0x68);
    }
    else {
      lVar7 = FUN_23e8ffa20();
      if (lVar7 == 0) {
        FUN_23e915740(param_1,&local_78,DAT_23eea85e8);
        pcVar21 = local_68;
        pcVar16 = local_78;
        plVar9 = plStack_70;
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(lVar7,DAT_23eea85f8);
        lVar7 = DAT_23eea8600;
        if (plVar9 != (longlong *)0x0) {
          lVar18 = 0;
          local_78 = (code *)&DAT_23ec5a40c;
          lVar13 = *(longlong *)(DAT_23eea8600 + 0x10);
          plVar10 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),lVar13);
          if (0 < lVar13) {
            do {
              lVar11 = FUN_23e971d80(param_1,*(undefined8 *)(lVar7 + 0x18 + lVar18 * 8),&local_78);
              plVar10[lVar18 + 3] = lVar11;
              lVar18 = lVar18 + 1;
            } while (lVar13 != lVar18);
          }
          local_78 = _Py_TrueStruct_exref;
          *(undefined4 *)(plVar2 + 5) = 0x18;
          plStack_70 = plVar9;
          plVar12 = (longlong *)FUN_23e9188e0(param_1,plVar8,plVar10,&local_78,DAT_23eea8608);
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))(plVar10);
          }
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar12 != (longlong *)0x0) {
            *plVar12 = *plVar12 + -1;
            if (*plVar12 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
            lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar9 = *(longlong **)(lVar7 + 0x28);
            plVar2 = (longlong *)plVar9[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
            *(undefined4 *)(plVar9 + 8) = 0xffffffff;
            if (plVar2 != (longlong *)0x0) {
              plVar9[2] = 0;
              *plVar2 = *plVar2 + -1;
              if (*plVar2 == 0) {
                (**(code **)(plVar2[1] + 0x30))();
              }
            }
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              (**(code **)(plVar9[1] + 0x30))(plVar9);
            }
            plVar2 = DAT_23eea8618;
            plVar9[0xf] = 0;
            *plVar2 = *plVar2 + 1;
            return plVar2;
          }
          goto LAB_23e129120;
        }
        pcVar21 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcVar16 = *(code **)(param_1 + 0x60);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar9 = *(longlong **)(param_1 + 0x68);
      }
      *plVar8 = *plVar8 + -1;
      uVar17 = 0x19;
      if (*plVar8 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
    }
  }
  plVar8 = *(longlong **)(param_1 + 0x138);
  local_98._8_8_ = plVar9;
  local_98._0_8_ = pcVar16;
  if (plVar8 != (longlong *)0x0) {
    *plVar8 = *plVar8 + 1;
  }
  pcVar16 = DAT_23ed6a4f8;
  local_88[0] = pcVar21;
  if (pcVar21 == (code *)0x0) {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar21 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar21;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong *)(pcVar16 + 0x10) = 0;
    *(longlong **)(pcVar16 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    *(undefined4 *)(pcVar16 + 0x24) = uVar17;
    pcVar20 = _PyRuntime_exref;
    *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = *(longlong *)(pcVar16 + -8);
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = pcVar16 + -0x10;
    *(longlong *)(pcVar16 + -0x10) = lVar7;
    *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
    *(code **)(lVar7 + 8) = pcVar16 + -0x10;
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))(local_88[0]);
    }
  }
  else {
    if (DAT_23ed6a4f8 == (code *)0x0) {
      pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      pcVar20 = *(code **)DAT_23ed6a4f8;
      *(longlong *)DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = pcVar20;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    *(longlong **)(pcVar16 + 0x18) = plVar2;
    *plVar2 = *plVar2 + 1;
    *(undefined4 *)(pcVar16 + 0x24) = uVar17;
    pcVar20 = _PyRuntime_exref;
    *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
    lVar7 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar20 + 0x1f8) + 0x10) + 0x2e8);
    lVar13 = *(longlong *)(pcVar16 + -8);
    puVar3 = *(undefined8 **)(lVar7 + 8);
    *puVar3 = pcVar16 + -0x10;
    *(longlong *)(pcVar16 + -0x10) = lVar7;
    *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
    *(code **)(lVar7 + 8) = pcVar16 + -0x10;
    *(code **)(pcVar16 + 0x10) = pcVar21;
    *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
    if ((local_88[0] != (code *)0x0) &&
       (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
      (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
    }
  }
  pcVar21 = _Py_NoneStruct_exref;
  local_88[0] = pcVar16;
  if (((code *)local_98._0_8_ != (code *)0x0) && ((code *)local_98._0_8_ != _Py_NoneStruct_exref)) {
    FUN_23e91b1b0(param_1,local_98,local_98 + 8,local_88);
  }
  plVar9 = *(longlong **)(local_98._8_8_ + 0x28);
  if (local_88[0] == pcVar21) {
    pcVar16 = (code *)0x0;
  }
  else {
    pcVar16 = local_88[0];
    if (local_88[0] != (code *)0x0) {
      *(longlong *)local_88[0] = *(longlong *)local_88[0] + 1;
    }
  }
  *(code **)(local_98._8_8_ + 0x28) = pcVar16;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  plVar9 = *(longlong **)(param_1 + 0x138);
  *(undefined8 *)(param_1 + 0x138) = local_98._8_8_;
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))();
  }
  *(longlong *)local_98._0_8_ = *(longlong *)local_98._0_8_ + -1;
  if (*(longlong *)local_98._0_8_ == 0) {
    (**(code **)(*(longlong *)(local_98._0_8_ + 8) + 0x30))();
  }
  if ((local_88[0] != (code *)0x0) &&
     (*(longlong *)local_88[0] = *(longlong *)local_88[0] + -1, *(longlong *)local_88[0] == 0)) {
    (**(code **)(*(longlong *)(local_88[0] + 8) + 0x30))();
  }
  pcVar19 = *(code **)(param_1 + 0x138);
  local_88[0] = (code *)0x0;
  local_98 = (undefined1  [16])0x0;
  pcVar15 = *(code **)(pcVar19 + 8);
  pcVar16 = *(code **)PyExc_Exception_exref;
  if ((*(uint *)(*(longlong *)(pcVar16 + 8) + 0xa8) & 0x4000000) == 0) {
    if (((int)*(uint *)(*(longlong *)(pcVar16 + 8) + 0xa8) < 0) &&
       (((byte)pcVar16[0xab] & 0x40) != 0)) {
      local_b0 = *(code **)(pcVar15 + 8);
      pcVar1 = local_b0 + 0xa8;
      if ((*(uint *)pcVar1 & 0x40000000) == 0) {
        local_b0 = pcVar15;
        if (((int)*(uint *)pcVar1 < 0) && (((byte)pcVar15[0xab] & 0x40) != 0)) goto LAB_23e129693;
      }
      else {
        pcVar15 = local_b0;
        if (*(int *)(*(longlong *)(local_b0 + 8) + 0xa8) < 0) goto LAB_23e129693;
      }
      if (pcVar16 != local_b0) goto LAB_23e12936a;
    }
    else {
LAB_23e129470:
      plVar9 = *(longlong **)PyExc_TypeError_exref;
      uVar14 = PyUnicode_FromString
                         ("catching classes that do not inherit from BaseException is not allowed");
      plVar10 = *(longlong **)(param_1 + 0x60);
      plVar12 = *(longlong **)(param_1 + 0x68);
      plVar4 = *(longlong **)(param_1 + 0x70);
      *(longlong **)(param_1 + 0x60) = plVar9;
      *plVar9 = *plVar9 + 1;
      *(undefined8 *)(param_1 + 0x68) = uVar14;
      *(undefined8 *)(param_1 + 0x70) = 0;
      if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
        (**(code **)(plVar10[1] + 0x30))();
      }
      if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      if ((plVar4 == (longlong *)0x0) || (*plVar4 = *plVar4 + -1, *plVar4 != 0)) {
LAB_23e1294d4:
        pcVar19 = *(code **)(param_1 + 0x138);
      }
      else {
        (**(code **)(plVar4[1] + 0x30))(plVar4);
        pcVar19 = *(code **)(param_1 + 0x138);
      }
    }
LAB_23e1294db:
    do {
      lVar7 = *(longlong *)(param_1 + 0x10);
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
      plVar9 = DAT_23eea8610;
      pcVar15 = *(code **)(lVar7 + 0xe20);
      if (pcVar15 == (code *)0x0) {
        pcVar15 = (code *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar13 = *(longlong *)(pcVar15 + 0x18);
        *(int *)(lVar7 + 0xebc) = *(int *)(lVar7 + 0xebc) + -1;
        *(longlong *)(lVar7 + 0xe20) = lVar13;
        *(longlong *)pcVar15 = 1;
      }
      lVar7 = *(longlong *)(pcVar20 + 0x1f8);
      pcVar16 = (code *)&DAT_23ed6a4c0;
      *(longlong *)(pcVar15 + 0x20) = 0;
      lVar7 = *(longlong *)(*(longlong *)(lVar7 + 0x10) + 0x2e8);
      lVar13 = *(longlong *)(pcVar15 + -8);
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = pcVar15 + -0x10;
      *(longlong *)(pcVar15 + -0x10) = lVar7;
      *(ulonglong *)(pcVar15 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
      *(code **)(lVar7 + 8) = pcVar15 + -0x10;
      plVar10 = DAT_23ed6a4c0;
      *plVar9 = *plVar9 + 1;
      *(longlong **)(pcVar15 + 0x18) = plVar9;
      uVar14 = DAT_23ed6cd28;
      pcVar21 = (code *)&DAT_23ed6cce0;
      if (plVar10 != (longlong *)0x0) {
LAB_23e129585:
        uStack_a0 = uVar14;
        local_a8 = pcVar19;
        lVar7 = FUN_23e94ed00(param_1,plVar10,&local_a8);
        if (lVar7 == 0) {
          local_b0 = *(code **)(param_1 + 0x68);
          plVar9 = *(longlong **)(param_1 + 0x60);
          pcVar21 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) {
            (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
          }
          lVar7 = *(longlong *)pcVar19;
        }
        else {
          *(longlong *)(pcVar15 + 0x20) = lVar7;
          plVar9 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar15);
          *(longlong *)pcVar15 = *(longlong *)pcVar15 + -1;
          if (*(longlong *)pcVar15 == 0) {
            (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
          }
          lVar7 = *(longlong *)pcVar19;
          if (plVar9 != (longlong *)0x0) {
            *(longlong *)pcVar19 = lVar7 + -1;
            if (lVar7 + -1 == 0) {
              (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
            }
            plVar2 = *(longlong **)(param_1 + 0x138);
            *(longlong **)(param_1 + 0x138) = plVar8;
            if ((plVar2 != (longlong *)0x0) && (*plVar2 = *plVar2 + -1, *plVar2 == 0)) {
              (**(code **)(plVar2[1] + 0x30))();
            }
            lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
            plVar2 = *(longlong **)(lVar7 + 0x28);
            plVar8 = (longlong *)plVar2[2];
            *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
            *(undefined4 *)(plVar2 + 8) = 0xffffffff;
            if (plVar8 != (longlong *)0x0) {
              plVar2[2] = 0;
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                (**(code **)(plVar8[1] + 0x30))();
              }
            }
            *plVar2 = *plVar2 + -1;
            if (*plVar2 == 0) {
              (**(code **)(plVar2[1] + 0x30))(plVar2);
            }
            plVar2[0xf] = 0;
            return plVar9;
          }
          local_b0 = *(code **)(param_1 + 0x68);
          plVar9 = *(longlong **)(param_1 + 0x60);
          pcVar21 = *(code **)(param_1 + 0x70);
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          *(undefined8 *)(param_1 + 0x70) = 0;
        }
        *(longlong *)pcVar19 = lVar7 + -1;
        if (lVar7 + -1 == 0) {
          (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
        }
        plVar10 = *(longlong **)(param_1 + 0x138);
        *(longlong **)(param_1 + 0x138) = plVar8;
        pcVar16 = pcVar21;
        if (plVar10 == (longlong *)0x0) {
          if (pcVar21 != (code *)0x0) {
            if (plVar2 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e129950;
LAB_23e129ba3:
            uVar17 = 0x21;
            goto LAB_23e1293d3;
          }
        }
        else {
          *plVar10 = *plVar10 + -1;
          if (*plVar10 == 0) {
            (**(code **)(plVar10[1] + 0x30))();
            if (pcVar21 != (code *)0x0) {
              iVar6 = 0x21;
              goto LAB_23e129b45;
            }
          }
          else if (pcVar21 != (code *)0x0) {
            if (*(longlong **)(pcVar21 + 0x18) != plVar2) goto LAB_23e129ba3;
            goto LAB_23e129950;
          }
        }
        iVar6 = 0x21;
        goto LAB_23e1298bc;
      }
      plVar10 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar10 != (longlong *)0x0) {
        *plVar10 = *plVar10 + 1;
        DAT_23ed6a4c0 = plVar10;
        goto LAB_23e129585;
      }
      PyErr_PrintEx(0,0);
      Py_Exit(1);
LAB_23e129693:
      lVar7 = *(longlong *)(pcVar15 + 0x158);
      if (lVar7 != 0) {
        if (*(longlong *)(lVar7 + 0x10) < 1) break;
        lVar13 = 0;
        while (pcVar16 != *(code **)(lVar7 + 0x18 + lVar13 * 8)) {
          lVar13 = lVar13 + 1;
          if (*(longlong *)(lVar7 + 0x10) == lVar13) goto LAB_23e12936a;
        }
        goto LAB_23e1294db;
      }
      do {
        if (pcVar16 == pcVar15) goto LAB_23e1294db;
        pcVar15 = *(code **)(pcVar15 + 0x100);
      } while (pcVar15 != (code *)0x0);
    } while (pcVar16 == PyBaseObject_Type_exref);
  }
  else {
    lVar7 = *(longlong *)(pcVar16 + 0x10);
    if (0 < lVar7) {
      lVar13 = 0;
      do {
        if ((-1 < *(int *)(*(longlong *)(*(longlong *)(pcVar16 + lVar13 * 8 + 0x18) + 8) + 0xa8)) ||
           ((*(byte *)(*(longlong *)(pcVar16 + lVar13 * 8 + 0x18) + 0xab) & 0x40) == 0))
        goto LAB_23e129470;
        lVar13 = lVar13 + 1;
      } while (lVar7 != lVar13);
      lVar13 = 0;
      do {
        iVar6 = FUN_23a35ebd0(param_1,pcVar15,*(undefined8 *)(pcVar16 + lVar13 * 8 + 0x18));
        if (iVar6 != 0) goto LAB_23e1294d4;
        lVar13 = lVar13 + 1;
      } while (lVar7 != lVar13);
      pcVar19 = *(code **)(param_1 + 0x138);
    }
  }
LAB_23e12936a:
  if ((pcVar19 == pcVar21) || (pcVar19 == (code *)0x0)) {
    iVar6 = 0x16;
    plVar9 = *(longlong **)PyExc_RuntimeError_exref;
    local_b0 = (code *)PyUnicode_FromString("No active exception to reraise");
    pcVar19 = *(code **)(param_1 + 0x138);
    *plVar9 = *plVar9 + 1;
    *(longlong **)(param_1 + 0x138) = plVar8;
    if ((pcVar19 != (code *)0x0) &&
       (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, iVar5 = 0x16, *(longlong *)pcVar19 == 0))
    {
LAB_23e129c47:
      iVar6 = iVar5;
      (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
      if (iVar6 == 0) goto LAB_23e129c5f;
    }
  }
  else {
    plVar9 = *(longlong **)(pcVar19 + 8);
    pcVar21 = *(code **)(pcVar19 + 0x28);
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
    *plVar9 = *plVar9 + 1;
    local_b0 = pcVar19;
    if (pcVar21 != (code *)0x0) {
      *(longlong *)pcVar21 = *(longlong *)pcVar21 + 1;
      if (plVar2 == *(longlong **)(pcVar21 + 0x18)) {
        *(undefined4 *)(plVar2 + 5) = *(undefined4 *)(pcVar21 + 0x24);
      }
      *(longlong **)(param_1 + 0x138) = plVar8;
      *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
      if (*(longlong *)pcVar19 == 0) {
        (*(code *)plVar9[6])(pcVar19);
        iVar6 = 0;
LAB_23e129b45:
        pcVar16 = pcVar21;
        if (plVar2 == *(longlong **)(pcVar21 + 0x18)) goto LAB_23e129950;
        uVar17 = 0x21;
        if (iVar6 == 0) goto LAB_23e1293d0;
      }
      else {
        pcVar16 = pcVar21;
        if (*(longlong **)(pcVar21 + 0x18) == plVar2) goto LAB_23e129950;
LAB_23e1293d0:
        uVar17 = (undefined4)plVar2[5];
      }
LAB_23e1293d3:
      pcVar16 = DAT_23ed6a4f8;
      if (DAT_23ed6a4f8 == (code *)0x0) {
        pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      }
      else {
        pcVar19 = *(code **)DAT_23ed6a4f8;
        *(longlong *)DAT_23ed6a4f8 = 1;
        DAT_23ed6a4f8 = pcVar19;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      }
      *(longlong **)(pcVar16 + 0x18) = plVar2;
      *plVar2 = *plVar2 + 1;
      lVar7 = *(longlong *)(pcVar20 + 0x1f8);
      *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
      lVar7 = *(longlong *)(lVar7 + 0x10);
      *(undefined4 *)(pcVar16 + 0x24) = uVar17;
      lVar7 = *(longlong *)(lVar7 + 0x2e8);
      lVar13 = *(longlong *)(pcVar16 + -8);
      puVar3 = *(undefined8 **)(lVar7 + 8);
      *puVar3 = pcVar16 + -0x10;
      *(longlong *)(pcVar16 + -0x10) = lVar7;
      *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
      lVar13 = *(longlong *)pcVar21;
      *(code **)(lVar7 + 8) = pcVar16 + -0x10;
      *(code **)(pcVar16 + 0x10) = pcVar21;
      if (lVar13 == 0) {
        (**(code **)(*(longlong *)(pcVar21 + 8) + 0x30))(pcVar21);
      }
      goto LAB_23e129950;
    }
    *(longlong **)(param_1 + 0x138) = plVar8;
    *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
    if (*(longlong *)pcVar19 == 0) {
      iVar5 = 0;
      goto LAB_23e129c47;
    }
LAB_23e129c5f:
    iVar6 = (int)plVar2[5];
  }
LAB_23e1298bc:
  pcVar16 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar16 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar21 = *(code **)DAT_23ed6a4f8;
    *(longlong *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar21;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar16 + 0x10) = 0;
  *(longlong **)(pcVar16 + 0x18) = plVar2;
  *plVar2 = *plVar2 + 1;
  lVar7 = *(longlong *)(pcVar20 + 0x1f8);
  *(undefined4 *)(pcVar16 + 0x20) = 0xffffffff;
  lVar7 = *(longlong *)(lVar7 + 0x10);
  *(int *)(pcVar16 + 0x24) = iVar6;
  lVar7 = *(longlong *)(lVar7 + 0x2e8);
  lVar13 = *(longlong *)(pcVar16 + -8);
  puVar3 = *(undefined8 **)(lVar7 + 8);
  *puVar3 = pcVar16 + -0x10;
  *(longlong *)(pcVar16 + -0x10) = lVar7;
  *(ulonglong *)(pcVar16 + -8) = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar3;
  *(code **)(lVar7 + 8) = pcVar16 + -0x10;
LAB_23e129950:
  FUN_23e8bba40(plVar2,&DAT_23ec5a08d,0);
  if (DAT_23eeaae80 == plVar2) {
    *plVar2 = *plVar2 + -1;
    if (*plVar2 == 0) {
      (**(code **)(plVar2[1] + 0x30))(plVar2);
    }
    DAT_23eeaae80 = (longlong *)0x0;
  }
  lVar7 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar2 = *(longlong **)(lVar7 + 0x28);
  plVar8 = (longlong *)plVar2[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar7 + 0x30);
  *(undefined4 *)(plVar2 + 8) = 0xffffffff;
  if (plVar8 != (longlong *)0x0) {
    plVar2[2] = 0;
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))();
    }
  }
  *plVar2 = *plVar2 + -1;
  if (*plVar2 == 0) {
    (**(code **)(plVar2[1] + 0x30))(plVar2);
  }
  plVar2[0xf] = 0;
  FUN_23a33aa70(param_1,plVar9,local_b0,pcVar16);
  return (longlong *)0x0;
}
