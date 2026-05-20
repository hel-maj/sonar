/* ===== 23e826c80 workers.fishing.path_utils:50 ===== */
/* ghidra_name=FUN_23e826c80 entry=23e826c80 size=2220 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e826c80(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  undefined8 *puVar1;
  code *pcVar2;
  code *pcVar3;
  undefined1 auVar4 [16];
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong lVar9;
  undefined8 uVar10;
  longlong *plVar11;
  longlong *plVar12;
  longlong lVar13;
  longlong *plVar14;
  longlong *plVar15;
  undefined8 *puVar16;
  undefined8 uVar17;
  longlong lVar18;
  undefined8 uVar19;
  undefined8 *puVar20;
  undefined4 uVar21;
  undefined8 in_stack_fffffffffffffe18;
  undefined8 in_stack_fffffffffffffe20;
  uint uVar23;
  ulonglong uVar22;
  undefined8 in_stack_fffffffffffffe28;
  uint uVar25;
  ulonglong uVar24;
  undefined8 in_stack_fffffffffffffe30;
  uint uVar26;
  undefined8 in_stack_fffffffffffffe38;
  uint uVar28;
  ulonglong uVar27;
  undefined8 uStack_1b8;
  longlong lStack_1b0;
  code *pcStack_1a8;
  undefined8 uStack_1a0;
  undefined8 uStack_198;
  longlong *plStack_180;
  longlong *plStack_178;
  longlong lStack_170;
  undefined8 *puStack_168;
  longlong *plStack_160;
  undefined8 *puStack_158;
  longlong *plStack_150;
  longlong *plStack_120;
  undefined8 uStack_118;
  undefined1 auStack_110 [16];
  longlong *plStack_100;
  longlong *plStack_f0;
  undefined8 uStack_e8;
  longlong *plStack_d8;
  longlong lStack_d0;
  longlong *plStack_c8;
  undefined8 *puStack_c0;
  longlong *plStack_b8;
  undefined8 *puStack_b0;
  longlong *plStack_88;
  undefined8 uStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar7 = _DAT_23eede750;
  uVar21 = (undefined4)((ulonglong)in_stack_fffffffffffffe18 >> 0x20);
  uVar26 = (uint)((ulonglong)in_stack_fffffffffffffe30 >> 0x20);
  uVar28 = (uint)((ulonglong)in_stack_fffffffffffffe38 >> 0x20);
  uVar23 = (uint)((ulonglong)in_stack_fffffffffffffe20 >> 0x20);
  uVar25 = (uint)((ulonglong)in_stack_fffffffffffffe28 >> 0x20);
  plVar14 = (longlong *)*param_3;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23eede750 == (longlong *)0x0) {
LAB_23e826cd1:
    puStack_b0 = (undefined8 *)0x23e826ced;
    _DAT_23eede750 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede748,DAT_23eede778,0x10);
  }
  else {
    lVar9 = *_DAT_23eede750;
    if (1 < lVar9) {
      *_DAT_23eede750 = lVar9 + -1;
      goto LAB_23e826cd1;
    }
    if (_DAT_23eede750[2] != 0) {
      *_DAT_23eede750 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        puStack_b0 = (undefined8 *)0x23e82711a;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e826cd1;
    }
  }
  plVar15 = _DAT_23eede750;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eede750 + 9;
  lVar13 = *(longlong *)(lVar9 + 8);
  _DAT_23eede750[0xf] = lVar13;
  *(longlong **)(lVar9 + 8) = plVar7;
  if ((lVar13 != 0) &&
     (((*(char *)(lVar13 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar13 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar13 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar13 + 0x38))) && (plVar15[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar13 + 0x28);
    *(longlong **)(plVar15[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar13 = DAT_23eedcfd0;
  *plVar15 = *plVar15 + 1;
  *(undefined4 *)(plVar15 + 8) = 0;
  lVar9 = *(longlong *)(lVar13 + 0x20);
  if (*(char *)(lVar9 + 10) == '\0') {
    puStack_b0 = (undefined8 *)0x23e8273fc;
    plVar7 = (longlong *)FUN_23a37a020(lVar13,DAT_23eedd038);
    if (plVar7 == (longlong *)0x0) goto LAB_23e826f19;
    lVar9 = *plVar7;
LAB_23e827408:
    if (lVar9 == 0) goto LAB_23e826f19;
  }
  else {
    iVar6 = *(int *)(lVar9 + 0xc);
    if (*(int *)(lVar9 + 0xc) == 0) {
      *(int *)(lVar9 + 0xc) = _DAT_23ec15568;
      iVar6 = _DAT_23ec15568;
      _DAT_23ec15568 = _DAT_23ec15568 + 1;
    }
    if (_DAT_23ec15564 != iVar6) {
      puStack_b0 = (undefined8 *)0x23e826f09;
      _DAT_23ec15564 = iVar6;
      _DAT_23eede740 = FUN_23e8cbd60(lVar9,DAT_23eedd038,*(undefined8 *)(DAT_23eedd038 + 0x18));
    }
    if (-1 < _DAT_23eede740) {
      lVar13 = lVar9 + 0x20 + (1L << (*(byte *)(lVar9 + 9) & 0x3f));
      if (*(longlong *)(lVar13 + 8 + _DAT_23eede740 * 0x10) != 0) goto LAB_23e826dc1;
      puStack_b0 = (undefined8 *)0x23e827483;
      _DAT_23eede740 = FUN_23e8cbd60(lVar9,DAT_23eedd038,*(undefined8 *)(DAT_23eedd038 + 0x18));
      if (-1 < _DAT_23eede740) {
        lVar9 = *(longlong *)(lVar13 + 8 + _DAT_23eede740 * 0x10);
        goto LAB_23e827408;
      }
    }
LAB_23e826f19:
    puStack_b0 = (undefined8 *)0x23e826f2f;
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eedd038);
    if ((plVar7 == (longlong *)0x0) || (*plVar7 == 0)) {
      uVar21 = 0x3c;
      plVar8 = (longlong *)0x0;
      puStack_b0 = (undefined8 *)0x23e826f5c;
      FUN_23e915740(param_1,auStack_78,DAT_23eedd038);
      plVar7 = plStack_68;
      plVar11 = DAT_23ed6a4f8;
      goto joined_r0x00023e82718c;
    }
  }
LAB_23e826dc1:
  *(undefined4 *)(plVar15 + 5) = 0x3c;
  puStack_b0 = (undefined8 *)0x23e826dd0;
  plVar7 = (longlong *)FUN_23e91a870(param_1);
  if (plVar7 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    plVar8 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar21 = 0x3c;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e82718c;
  }
  puStack_b0 = (undefined8 *)0x23e826de7;
  plVar8 = (longlong *)FUN_23e8c6f80(plVar7,plVar14);
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_b0 = (undefined8 *)0x23e826dfb;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  if (plVar8 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar7 = *(longlong **)(param_1 + 0x70);
    uVar21 = 0x3c;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar11 = DAT_23ed6a4f8;
    goto joined_r0x00023e82718c;
  }
  *(undefined4 *)(plVar15 + 5) = 0x3e;
  puStack_b0 = (undefined8 *)0x23e826e24;
  plVar7 = (longlong *)FUN_23e91bfe0(param_1,plVar8,DAT_23ed6cee0);
  if (plVar7 != (longlong *)0x0) {
    puStack_b0 = (undefined8 *)0x23e826e38;
    iVar6 = FUN_23a35f020(plVar7);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_b0 = (undefined8 *)0x23e826e4c;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    plVar7 = _DAT_23eedd040;
    if (iVar6 != -1) {
      if (iVar6 != 0) {
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar7 = *(longlong **)(lVar9 + 0x28);
        plVar15 = (longlong *)plVar7[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar7 + 8) = 0xffffffff;
        if (plVar15 != (longlong *)0x0) {
          plVar7[2] = 0;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            puStack_b0 = (undefined8 *)0x23e826e98;
            (**(code **)(plVar15[1] + 0x30))();
          }
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_b0 = (undefined8 *)0x23e826ea8;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar9 = *plVar8;
        plVar7[0xf] = 0;
        if (lVar9 == 0) {
          puStack_b0 = (undefined8 *)0x23e826ec0;
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        *plVar14 = *plVar14 + -1;
        if (*plVar14 != 0) {
          return plVar8;
        }
        puStack_b0 = (undefined8 *)0x23e826ed2;
        (**(code **)(plVar14[1] + 0x30))(plVar14);
        return plVar8;
      }
      lVar9 = *(longlong *)(param_1 + 0x10);
      plVar12 = *(longlong **)(lVar9 + 0xe20);
      if (plVar12 == (longlong *)0x0) {
        puStack_b0 = (undefined8 *)0x23e827511;
        plVar12 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
      }
      else {
        lVar13 = plVar12[3];
        *(int *)(lVar9 + 0xebc) = *(int *)(lVar9 + 0xebc) + -1;
        *(longlong *)(lVar9 + 0xe20) = lVar13;
        *plVar12 = 1;
      }
      pcVar3 = _PyRuntime_exref;
      plVar12[4] = 0;
      lVar9 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar3 + 0x1f8) + 0x10) + 0x2e8);
      lVar13 = plVar12[-1];
      puVar20 = *(undefined8 **)(lVar9 + 8);
      *puVar20 = plVar12 + -2;
      plVar12[-2] = lVar9;
      plVar12[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar20;
      *(longlong **)(lVar9 + 8) = plVar12 + -2;
      *plVar7 = *plVar7 + 1;
      plVar12[3] = (longlong)plVar7;
      uVar10 = DAT_23ed6cd28;
      if (DAT_23ed6a4c0 == (longlong *)0x0) {
        puStack_b0 = (undefined8 *)0x23e827537;
        plVar7 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar7 == (longlong *)0x0) {
          puStack_b0 = (undefined8 *)0x23e827571;
          PyErr_PrintEx(0,0);
          lVar9 = 1;
          puStack_b0 = (undefined8 *)0x23e82757c;
          Py_Exit();
          plVar7 = _DAT_23eede738;
          puStack_b0 = &DAT_23ed6cce0;
          puStack_c0 = &DAT_23ed6a4c0;
          uStack_e8 = uVar10;
          plStack_100 = (longlong *)0x0;
          auStack_110 = (undefined1  [16])0x0;
          plStack_f0 = plVar8;
          plStack_d8 = plVar15;
          lStack_d0 = param_1;
          plStack_c8 = plVar8;
          plStack_b8 = plVar14;
          if (_DAT_23eede738 == (longlong *)0x0) {
LAB_23e8275ca:
            _DAT_23eede738 = (longlong *)FUN_23e91f3b0(lVar9,DAT_23eede730,DAT_23eede778,8);
          }
          else {
            lVar13 = *_DAT_23eede738;
            if (1 < lVar13) {
              *_DAT_23eede738 = lVar13 + -1;
              goto LAB_23e8275ca;
            }
            if (_DAT_23eede738[2] != 0) {
              *_DAT_23eede738 = lVar13 + -1;
              if (lVar13 + -1 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              goto LAB_23e8275ca;
            }
          }
          plVar7 = _DAT_23eede738;
          lVar13 = *(longlong *)(lVar9 + 0x38);
          plVar14 = _DAT_23eede738 + 9;
          lVar18 = *(longlong *)(lVar13 + 8);
          _DAT_23eede738[0xf] = lVar18;
          *(longlong **)(lVar13 + 8) = plVar14;
          if (((lVar18 != 0) &&
              ((*(char *)(lVar18 + 0x45) == '\x01' ||
               ((ulonglong)
                (*(longlong *)(lVar18 + 0x20) + 0xb8 +
                (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
                *(ulonglong *)(lVar18 + 0x38))))) && (plVar7[0xe] != 0)) {
            plVar14 = *(longlong **)(lVar18 + 0x28);
            *(longlong **)(plVar7[0xe] + 0x10) = plVar14;
            if (plVar14 != (longlong *)0x0) {
              *plVar14 = *plVar14 + 1;
            }
          }
          *plVar7 = *plVar7 + 1;
          *(undefined4 *)(plVar7 + 8) = 0;
          lVar13 = FUN_23e8dc1d0();
          if (lVar13 == 0) {
            uVar21 = 0x46;
            FUN_23e915740(lVar9,auStack_110,DAT_23eedd020);
            plVar15 = (longlong *)0x0;
            plVar8 = DAT_23ed6a4f8;
            plVar14 = plStack_100;
            goto joined_r0x00023e8278dc;
          }
          *(undefined4 *)(plVar7 + 5) = 0x46;
          plVar14 = (longlong *)FUN_23e91a870(lVar9,lVar13);
          if (plVar14 == (longlong *)0x0) {
            auStack_110 = *(undefined1 (*) [16])(lVar9 + 0x60);
            plVar14 = *(longlong **)(lVar9 + 0x70);
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar9 + 0x70) = 0;
            uVar21 = 0x46;
            *(undefined1 (*) [16])(lVar9 + 0x60) = (undefined1  [16])0x0;
            plVar8 = DAT_23ed6a4f8;
            goto joined_r0x00023e8278dc;
          }
          plVar15 = (longlong *)FUN_23e8c6f80(plVar14,_DAT_23eedd050);
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          if (plVar15 == (longlong *)0x0) {
            auStack_110 = *(undefined1 (*) [16])(lVar9 + 0x60);
            plVar14 = *(longlong **)(lVar9 + 0x70);
            uVar21 = 0x46;
            *(undefined8 *)(lVar9 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar9 + 0x60) = (undefined1  [16])0x0;
            plVar8 = DAT_23ed6a4f8;
            goto joined_r0x00023e8278dc;
          }
          *(undefined4 *)(plVar7 + 5) = 0x48;
          plVar14 = (longlong *)FUN_23e91bfe0(lVar9,plVar15,DAT_23ed6cee0);
          if (plVar14 != (longlong *)0x0) {
            iVar6 = FUN_23a35f020(plVar14);
            *plVar14 = *plVar14 + -1;
            if (*plVar14 == 0) {
              (**(code **)(plVar14[1] + 0x30))(plVar14);
            }
            plVar14 = _DAT_23eedd058;
            if (iVar6 != -1) {
              if (iVar6 != 0) {
                lVar13 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
                plVar14 = *(longlong **)(lVar13 + 0x28);
                plVar7 = (longlong *)plVar14[2];
                *(undefined8 *)(*(longlong *)(lVar9 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
                *(undefined4 *)(plVar14 + 8) = 0xffffffff;
                if (plVar7 != (longlong *)0x0) {
                  plVar14[2] = 0;
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    (**(code **)(plVar7[1] + 0x30))();
                  }
                }
                *plVar14 = *plVar14 + -1;
                if (*plVar14 == 0) {
                  (**(code **)(plVar14[1] + 0x30))(plVar14);
                }
                lVar9 = *plVar15;
                plVar14[0xf] = 0;
                if (lVar9 != 0) {
                  return plVar15;
                }
                (**(code **)(plVar15[1] + 0x30))(plVar15);
                return plVar15;
              }
              lVar13 = *(longlong *)(lVar9 + 0x10);
              plVar11 = *(longlong **)(lVar13 + 0xe20);
              if (plVar11 == (longlong *)0x0) {
                plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
              }
              else {
                lVar18 = plVar11[3];
                *(int *)(lVar13 + 0xebc) = *(int *)(lVar13 + 0xebc) + -1;
                *(longlong *)(lVar13 + 0xe20) = lVar18;
                *plVar11 = 1;
              }
              pcVar3 = _PyRuntime_exref;
              plVar11[4] = 0;
              lVar13 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar3 + 0x1f8) + 0x10) + 0x2e8);
              lVar18 = plVar11[-1];
              puVar20 = *(undefined8 **)(lVar13 + 8);
              *puVar20 = plVar11 + -2;
              plVar11[-2] = lVar13;
              plVar11[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar20;
              *(longlong **)(lVar13 + 8) = plVar11 + -2;
              *plVar14 = *plVar14 + 1;
              plVar11[3] = (longlong)plVar14;
              uVar10 = DAT_23ed6cd28;
              if (DAT_23ed6a4c0 == (longlong *)0x0) {
                plVar14 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar14 == (longlong *)0x0) {
                  PyErr_PrintEx(0);
                  lVar13 = 1;
                  Py_Exit();
                  puStack_158 = &DAT_23ed6cce0;
                  puStack_168 = &DAT_23ed6a4c0;
                  DAT_23eedcfd0 = plVar14[2];
                  DAT_23eede778 = plVar14;
                  plStack_180 = plVar7;
                  plStack_178 = plVar15;
                  lStack_170 = lVar9;
                  plStack_160 = plVar11;
                  plStack_150 = plVar12;
                  if (DAT_23eede729 == '\0') {
                    if (DAT_23eede728 == '\0') {
                      FUN_23e97f860(lVar13,&DAT_23eedcfe0,"workers.fishing.path_utils");
                      DAT_23eede728 = '\x01';
                    }
                    _DAT_23eede720 = FUN_23e8bdab0(_DAT_23eedd0c8);
                    uVar24 = (ulonglong)uVar25 << 0x20;
                    uVar22 = (ulonglong)uVar23 << 0x20;
                    _DAT_23eede718 =
                         FUN_23e8d36c0(_DAT_23eede720,1,0,_DAT_23eedd0d0,_DAT_23eedd0d0,uVar22,
                                       uVar24);
                    uVar24 = uVar24 & 0xffffffff00000000;
                    DAT_23eede758 =
                         FUN_23e8d36c0(_DAT_23eede720,0x2d,3,DAT_23eedd038,DAT_23eedd038,
                                       uVar22 & 0xffffffff00000000,uVar24);
                    uVar27 = (ulonglong)uVar28 << 0x20;
                    uVar22 = (ulonglong)uVar26 << 0x20;
                    uVar24 = uVar24 & 0xffffffff00000000;
                    DAT_23eede730 =
                         FUN_23e8d3980(_DAT_23eede720,0x44,3,DAT_23eedd0c0,DAT_23eedd0c0,
                                       _DAT_23eedd0d8,uVar24,uVar22,uVar27);
                    uVar27 = uVar27 & 0xffffffff00000000;
                    uVar22 = uVar22 & 0xffffffff00000000;
                    DAT_23eede770 =
                         FUN_23e8d3980(_DAT_23eede720,10,3,DAT_23eedd020,DAT_23eedd020,
                                       _DAT_23eedd0e0,uVar24 & 0xffffffff00000000,uVar22,uVar27);
                    uVar10 = DAT_23eedd0b8;
                    DAT_23eede748 =
                         FUN_23e8d3980(_DAT_23eede720,0x32,3,DAT_23eedd0b8,DAT_23eedd0b8,
                                       _DAT_23eedd0e8,1,uVar22 & 0xffffffff00000000,
                                       uVar27 & 0xffffffff00000000);
                    uVar21 = (undefined4)((ulonglong)uVar10 >> 0x20);
                    DAT_23eede729 = '\x01';
                  }
                  FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cdd0,DAT_23ed6a4a8);
                  puVar16 = (undefined8 *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cd48);
                  uVar10 = 0;
                  if (puVar16 != (undefined8 *)0x0) {
                    uVar10 = *puVar16;
                  }
                  uVar17 = PyUnicode_GetLength(uVar10);
                  lVar9 = PyUnicode_Find(uVar10,DAT_23ed6cf48,0,uVar17,CONCAT44(uVar21,0xffffffff));
                  if (lVar9 != -1) {
                    uVar10 = PyUnicode_Substring(uVar10,0,lVar9);
                    FUN_23a3881f0(DAT_23eedcfd0,DAT_23ed6cd50,uVar10);
                  }
                  plVar14 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cda0);
                  if ((plVar14 == (longlong *)0x0) || (*plVar14 == 0)) {
                    uVar10 = PyModule_GetDict(DAT_23ed6a4a0);
                    FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cda0,uVar10);
                    puVar16 = DAT_23ed6a470;
                    if (DAT_23ed6a470 == (undefined8 *)0x0) goto LAB_23e828769;
LAB_23e827fe0:
                    DAT_23ed6a470 = (undefined8 *)*puVar16;
                    *puVar16 = 1;
                    DAT_23ed6a468 = DAT_23ed6a468 + -1;
                  }
                  else {
                    puVar16 = DAT_23ed6a470;
                    if (DAT_23ed6a470 != (undefined8 *)0x0) goto LAB_23e827fe0;
LAB_23e828769:
                    puVar16 = (undefined8 *)FUN_23a33a530(&DAT_23ec0f940);
                  }
                  pcVar3 = _PyRuntime_exref;
                  lVar9 = *(longlong *)
                           (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                  uVar10 = puVar16[-1];
                  puVar1 = *(undefined8 **)(lVar9 + 8);
                  *puVar1 = puVar16 + -2;
                  puVar16[-2] = lVar9;
                  puVar16[-1] = (ulonglong)((uint)uVar10 & 3) | (ulonglong)puVar1;
                  *(undefined8 **)(lVar9 + 8) = puVar16 + -2;
                  lVar9 = DAT_23eedcfd0;
                  puVar16[2] = puVar20;
                  FUN_23a3880f0(lVar9,DAT_23ed6cdc8);
                  if (DAT_23ed6a478 == 0) {
                    DAT_23ed6a478 = PyImport_ImportModule("importlib._bootstrap");
                  }
                  plVar14 = (longlong *)PyObject_GetAttrString(DAT_23ed6a478,"_spec_from_module");
                  lVar9 = FUN_23e914090(lVar13,plVar14,DAT_23eede778);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  pcVar2 = _Py_TrueStruct_exref;
                  if (lVar9 == 0) {
LAB_23e828a07:
                    PyErr_PrintEx(0);
                    /* WARNING: Subroutine does not return */
                    abort();
                  }
                  FUN_23e8d9ac0(lVar9,DAT_23ed6cfa8,_Py_TrueStruct_exref);
                  FUN_23a3881f0(DAT_23eedcfd0,DAT_23ed6cfa0,lVar9);
                  FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cd78,_DAT_23eedd068);
                  FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cd80,_DAT_23eede720);
                  plVar14 = (longlong *)FUN_23e9354d0(_DAT_23eede718,DAT_23eede778);
                  lVar9 = *(longlong *)(lVar13 + 0x38);
                  lVar18 = *(longlong *)(lVar9 + 8);
                  plVar14[0xf] = lVar18;
                  *(longlong **)(lVar9 + 8) = plVar14 + 9;
                  if ((lVar18 != 0) &&
                     (((*(char *)(lVar18 + 0x45) == '\x01' ||
                       ((ulonglong)
                        (*(longlong *)(lVar18 + 0x20) + 0xb8 +
                        (longlong)*(int *)(*(longlong *)(lVar18 + 0x20) + 0xa8) * 2) <=
                        *(ulonglong *)(lVar18 + 0x38))) && (plVar14[0xe] != 0)))) {
                    plVar7 = *(longlong **)(lVar18 + 0x28);
                    *(longlong **)(plVar14[0xe] + 0x10) = plVar7;
                    if (plVar7 != (longlong *)0x0) {
                      *plVar7 = *plVar7 + 1;
                    }
                  }
                  *plVar14 = *plVar14 + 1;
                  uVar10 = DAT_23ed6cfa0;
                  *(undefined4 *)(plVar14 + 8) = 0;
                  uVar17 = _DAT_23eede720;
                  plVar7 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,uVar10);
                  if ((plVar7 == (longlong *)0x0) || (lVar9 = *plVar7, lVar9 == 0)) {
                    lVar9 = FUN_23a3a6140();
                  }
                  cVar5 = FUN_23e8d9ac0(lVar9,_DAT_23eedd070,uVar17);
                  if (cVar5 != '\0') {
                    plVar7 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cfa0);
                    if ((plVar7 == (longlong *)0x0) || (lVar9 = *plVar7, lVar9 == 0)) {
                      lVar9 = FUN_23a3a6140();
                    }
                    cVar5 = FUN_23e8d9ac0(lVar9,_DAT_23eedd078,pcVar2);
                    pcVar2 = _Py_NoneStruct_exref;
                    if (cVar5 != '\0') {
                      FUN_23a3880f0(DAT_23eedcfd0,DAT_23ed6cf20,_Py_NoneStruct_exref);
                      if ((DAT_23ed6a210 == 0) &&
                         (DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec5e349), DAT_23ed6a210 == 0)
                         ) {
                        FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS",
                                      "\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
                        abort();
                      }
                      FUN_23a3880f0(DAT_23eedcfd0,_DAT_23eedd080,DAT_23ed6a210);
                      if ((DAT_23ed6a4b8 == 0) &&
                         (DAT_23ed6a4b8 = PyImport_ImportModule(&DAT_23ec5e386), DAT_23ed6a4b8 == 0)
                         ) {
                        FUN_23e9364c0("%s : %s\n","IMPORT_HARD_OS",
                                      "\"Unexpected failure of hard import of \'os\'\"");
                    /* WARNING: Subroutine does not return */
                        abort();
                      }
                      FUN_23a3880f0(DAT_23eedcfd0,DAT_23eedd088,DAT_23ed6a4b8);
                      uStack_1b8 = DAT_23eedd090;
                      uStack_198 = DAT_23ed6ccf0;
                      plVar7 = DAT_23ed6a498;
                      pcStack_1a8 = pcVar2;
                      uStack_1a0 = DAT_23eedd098;
                      *(undefined4 *)(plVar14 + 5) = 7;
                      lStack_1b0 = DAT_23eedcfd0;
                      if (plVar7 == (longlong *)0x0) {
                        plVar7 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"__import__");
                        if (plVar7 == (longlong *)0x0) {
                          PyErr_PrintEx(0,0);
                          Py_Exit(1);
                          goto LAB_23e828a07;
                        }
                        *plVar7 = *plVar7 + 1;
                        DAT_23ed6a498 = plVar7;
                      }
                      plVar7 = (longlong *)FUN_23e95b390(lVar13,plVar7,&uStack_1b8);
                      if (plVar7 != (longlong *)0x0) {
                        if (((code *)plVar7[1] == PyModule_Type_exref) ||
                           (iVar6 = PyType_IsSubtype(), uVar10 = DAT_23eedcfe8, iVar6 != 0)) {
                          uVar17 = DAT_23eedcfe8;
                          lVar9 = DAT_23eedcfd0;
                          uVar10 = DAT_23ed6ccf0;
                          lVar18 = PyObject_GetAttr(plVar7,DAT_23eedcfe8);
                          if (lVar18 != 0) goto LAB_23e828314;
                          lVar18 = FUN_23e970390(lVar13,plVar7,lVar9,uVar17,uVar10);
                        }
                        else {
                          lVar18 = PyObject_GetAttr(plVar7,DAT_23eedcfe8);
                          if (lVar18 != 0) {
LAB_23e828314:
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              (**(code **)(plVar7[1] + 0x30))(plVar7);
                            }
                            goto LAB_23e82831f;
                          }
                          lVar18 = FUN_23e8d2cf0(lVar13,plVar7,uVar10);
                        }
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          (**(code **)(plVar7[1] + 0x30))(plVar7);
                        }
                        if (lVar18 != 0) {
LAB_23e82831f:
                          FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedcfe8,lVar18);
                          lVar9 = *(longlong *)(*(longlong *)(lVar13 + 0x38) + 8);
                          plVar14 = *(longlong **)(lVar9 + 0x28);
                          plVar7 = (longlong *)plVar14[2];
                          *(undefined8 *)(*(longlong *)(lVar13 + 0x38) + 8) =
                               *(undefined8 *)(lVar9 + 0x30);
                          *(undefined4 *)(plVar14 + 8) = 0xffffffff;
                          if (plVar7 != (longlong *)0x0) {
                            plVar14[2] = 0;
                            *plVar7 = *plVar7 + -1;
                            if (*plVar7 == 0) {
                              (**(code **)(plVar7[1] + 0x30))();
                            }
                          }
                          *plVar14 = *plVar14 + -1;
                          if (*plVar14 == 0) {
                            (**(code **)(plVar14[1] + 0x30))(plVar14);
                          }
                          plVar14[0xf] = 0;
                          uVar10 = DAT_23eedd0a0;
                          uVar17 = FUN_23e8dc0a0();
                          uVar19 = _PyDict_NewPresized(1);
                          PyDict_SetItem(uVar19,uVar10,uVar17);
                          uVar10 = FUN_23e93df40(FUN_23e825840,DAT_23eedd020,DAT_23eede770,0,0,
                                                 uVar19,DAT_23eede778,DAT_23eedd018,0);
                          FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd020,uVar10);
                          uVar10 = DAT_23eedd0a0;
                          uVar17 = FUN_23e8dc0a0();
                          uVar19 = _PyDict_NewPresized(1);
                          PyDict_SetItem(uVar19,uVar10,uVar17);
                          uVar10 = FUN_23e93df40(FUN_23e826850,DAT_23eedd038,DAT_23eede758,0,0,
                                                 uVar19,DAT_23eede778,DAT_23eedd030,0);
                          FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd038,uVar10);
                          uVar10 = DAT_23eedd0b0;
                          plVar14 = DAT_23eedd0a8;
                          uVar17 = _PyDict_NewPresized(2);
                          PyDict_SetItem(uVar17,uVar10,PyUnicode_Type_exref);
                          uVar10 = DAT_23eedd0a0;
                          uVar19 = FUN_23e8dc0a0();
                          PyDict_SetItem(uVar17,uVar10,uVar19);
                          uVar10 = DAT_23eedd048;
                          *plVar14 = *plVar14 + 1;
                          uVar10 = FUN_23e93df40(FUN_23e826c80,DAT_23eedd0b8,DAT_23eede748,plVar14,0
                                                 ,uVar17,DAT_23eede778,uVar10,0);
                          FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd0b8,uVar10);
                          uVar10 = DAT_23eedd0a0;
                          uVar17 = FUN_23e8dc0a0();
                          uVar19 = _PyDict_NewPresized(1);
                          PyDict_SetItem(uVar19,uVar10,uVar17);
                          uVar10 = FUN_23e93df40(FUN_23e827580,DAT_23eedd0c0,DAT_23eede730,0,0,
                                                 uVar19,DAT_23eede778,DAT_23eedd060,0);
                          FUN_23a3881f0(DAT_23eedcfd0,DAT_23eedd0c0,uVar10);
                          plVar14 = DAT_23eede778;
                          *DAT_23eede778 = *DAT_23eede778 + 1;
                          return plVar14;
                        }
                      }
                      uVar10 = *(undefined8 *)(lVar13 + 0x60);
                      uVar17 = *(undefined8 *)(lVar13 + 0x68);
                      uVar21 = 7;
                      plVar7 = *(longlong **)(lVar13 + 0x70);
                      goto LAB_23e8285f2;
                    }
                  }
                  uVar10 = *(undefined8 *)(lVar13 + 0x60);
                  uVar17 = *(undefined8 *)(lVar13 + 0x68);
                  uVar21 = 1;
                  plVar7 = *(longlong **)(lVar13 + 0x70);
LAB_23e8285f2:
                  *(undefined8 *)(lVar13 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar13 + 0x60) = (undefined1  [16])0x0;
                  plVar15 = DAT_23ed6a4f8;
                  if (plVar7 == (longlong *)0x0) {
                    if (DAT_23ed6a4f8 == (longlong *)0x0) {
                      plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                    }
                    else {
                      plVar7 = (longlong *)*DAT_23ed6a4f8;
                      *DAT_23ed6a4f8 = 1;
                      DAT_23ed6a4f8 = plVar7;
                      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                    }
                    plVar15[2] = 0;
                    plVar15[3] = (longlong)plVar14;
                    *plVar14 = *plVar14 + 1;
                    lVar9 = *(longlong *)(pcVar3 + 0x1f8);
                    *(undefined4 *)(plVar15 + 4) = 0xffffffff;
                    lVar9 = *(longlong *)(lVar9 + 0x10);
                    *(undefined4 *)((longlong)plVar15 + 0x24) = uVar21;
                    lVar9 = *(longlong *)(lVar9 + 0x2e8);
                    lVar18 = plVar15[-1];
                    puVar20 = *(undefined8 **)(lVar9 + 8);
                    *puVar20 = plVar15 + -2;
                    plVar15[-2] = lVar9;
                    plVar15[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar20;
                    *(longlong **)(lVar9 + 8) = plVar15 + -2;
                    plVar8 = plVar15;
                  }
                  else {
                    plVar8 = plVar7;
                    if ((longlong *)plVar7[3] != plVar14) {
                      if (DAT_23ed6a4f8 == (longlong *)0x0) {
                        plVar15 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
                      }
                      else {
                        plVar8 = (longlong *)*DAT_23ed6a4f8;
                        *DAT_23ed6a4f8 = 1;
                        DAT_23ed6a4f8 = plVar8;
                        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                      }
                      plVar15[3] = (longlong)plVar14;
                      *plVar14 = *plVar14 + 1;
                      lVar9 = *(longlong *)(pcVar3 + 0x1f8);
                      *(undefined4 *)(plVar15 + 4) = 0xffffffff;
                      lVar9 = *(longlong *)(lVar9 + 0x10);
                      *(undefined4 *)((longlong)plVar15 + 0x24) = uVar21;
                      lVar9 = *(longlong *)(lVar9 + 0x2e8);
                      lVar18 = plVar15[-1];
                      puVar20 = *(undefined8 **)(lVar9 + 8);
                      *puVar20 = plVar15 + -2;
                      plVar15[-2] = lVar9;
                      plVar15[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar20;
                      lVar18 = *plVar7;
                      *(longlong **)(lVar9 + 8) = plVar15 + -2;
                      plVar15[2] = (longlong)plVar7;
                      plVar8 = plVar15;
                      if (lVar18 == 0) {
                        (**(code **)(plVar7[1] + 0x30))(plVar7);
                      }
                    }
                  }
                  lVar9 = *(longlong *)(*(longlong *)(lVar13 + 0x38) + 8);
                  plVar14 = *(longlong **)(lVar9 + 0x28);
                  plVar7 = (longlong *)plVar14[2];
                  *(undefined8 *)(*(longlong *)(lVar13 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
                  *(undefined4 *)(plVar14 + 8) = 0xffffffff;
                  if (plVar7 != (longlong *)0x0) {
                    plVar14[2] = 0;
                    *plVar7 = *plVar7 + -1;
                    if (*plVar7 == 0) {
                      (**(code **)(plVar7[1] + 0x30))();
                    }
                  }
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  plVar14[0xf] = 0;
                  FUN_23a33aa70(lVar13,uVar10,uVar17,plVar8);
                  return (longlong *)0x0;
                }
                *plVar14 = *plVar14 + 1;
                DAT_23ed6a4c0 = plVar14;
              }
              uStack_118 = uVar10;
              plStack_120 = plVar15;
              lVar13 = FUN_23e94ed00(lVar9,DAT_23ed6a4c0,&plStack_120);
              if (lVar13 == 0) {
                auStack_110 = *(undefined1 (*) [16])(lVar9 + 0x60);
                plStack_100 = *(longlong **)(lVar9 + 0x70);
                uVar21 = 0x49;
                *(undefined8 *)(lVar9 + 0x70) = 0;
                *(undefined1 (*) [16])(lVar9 + 0x60) = (undefined1  [16])0x0;
                *plVar11 = *plVar11 + -1;
                plVar8 = DAT_23ed6a4f8;
                plVar14 = plStack_100;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                  plVar8 = DAT_23ed6a4f8;
                  plVar14 = plStack_100;
                }
              }
              else {
                plVar11[4] = lVar13;
                plVar14 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                pcVar3 = PyExc_FileNotFoundError_exref;
                if (plVar14 == (longlong *)0x0) {
                  auStack_110 = *(undefined1 (*) [16])(lVar9 + 0x60);
                  plVar14 = *(longlong **)(lVar9 + 0x70);
                  uVar21 = 0x49;
                  *(undefined8 *)(lVar9 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar9 + 0x60) = (undefined1  [16])0x0;
                  plVar8 = DAT_23ed6a4f8;
                }
                else {
                  *(undefined4 *)(plVar7 + 5) = 0x49;
                  uVar10 = FUN_23e914090(lVar9,*(undefined8 *)pcVar3,plVar14);
                  *plVar14 = *plVar14 + -1;
                  if (*plVar14 == 0) {
                    (**(code **)(plVar14[1] + 0x30))(plVar14);
                  }
                  auStack_110._0_8_ = uVar10;
                  uVar21 = 0x49;
                  FUN_23e91b7d0(lVar9,auStack_110);
                  plVar8 = DAT_23ed6a4f8;
                  plVar14 = plStack_100;
                }
              }
              goto joined_r0x00023e8278dc;
            }
          }
          plVar14 = *(longlong **)(lVar9 + 0x70);
          auStack_110 = *(undefined1 (*) [16])(lVar9 + 0x60);
          uVar21 = 0x48;
          *(undefined8 *)(lVar9 + 0x70) = 0;
          *(undefined1 (*) [16])(lVar9 + 0x60) = (undefined1  [16])0x0;
          plVar8 = DAT_23ed6a4f8;
joined_r0x00023e8278dc:
          DAT_23ed6a4f8 = plVar8;
          plStack_100 = plVar14;
          if (plVar14 == (longlong *)0x0) {
            if (plVar8 == (longlong *)0x0) {
              plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              DAT_23ed6a4f8 = (longlong *)*plVar8;
              *plVar8 = 1;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            pcVar3 = _PyRuntime_exref;
            plVar8[3] = (longlong)plVar7;
            plVar8[2] = 0;
            *plVar7 = *plVar7 + 1;
            lVar13 = *(longlong *)(pcVar3 + 0x1f8);
            *(undefined4 *)(plVar8 + 4) = 0xffffffff;
            lVar13 = *(longlong *)(lVar13 + 0x10);
            *(undefined4 *)((longlong)plVar8 + 0x24) = uVar21;
            lVar13 = *(longlong *)(lVar13 + 0x2e8);
            lVar18 = plVar8[-1];
            puVar20 = *(undefined8 **)(lVar13 + 8);
            *puVar20 = plVar8 + -2;
            plVar8[-2] = lVar13;
            plVar8[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar20;
            *(longlong **)(lVar13 + 8) = plVar8 + -2;
            plVar14 = plVar8;
            if ((plStack_100 != (longlong *)0x0) &&
               (*plStack_100 = *plStack_100 + -1, *plStack_100 == 0)) {
              (**(code **)(plStack_100[1] + 0x30))(plStack_100);
            }
          }
          else if ((longlong *)plVar14[3] != plVar7) {
            if (plVar8 == (longlong *)0x0) {
              plVar8 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              DAT_23ed6a4f8 = (longlong *)*plVar8;
              *plVar8 = 1;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            pcVar3 = _PyRuntime_exref;
            plVar8[3] = (longlong)plVar7;
            *plVar7 = *plVar7 + 1;
            lVar13 = *(longlong *)(pcVar3 + 0x1f8);
            *(undefined4 *)((longlong)plVar8 + 0x24) = uVar21;
            *(undefined4 *)(plVar8 + 4) = 0xffffffff;
            lVar13 = *(longlong *)(*(longlong *)(lVar13 + 0x10) + 0x2e8);
            lVar18 = plVar8[-1];
            puVar20 = *(undefined8 **)(lVar13 + 8);
            *puVar20 = plVar8 + -2;
            plVar8[-2] = lVar13;
            plVar8[-1] = (ulonglong)((uint)lVar18 & 3) | (ulonglong)puVar20;
            *(longlong **)(lVar13 + 8) = plVar8 + -2;
            plVar8[2] = (longlong)plVar14;
            *plVar14 = *plVar14 + 1;
            plVar14 = plVar8;
            if ((plStack_100 != (longlong *)0x0) &&
               (*plStack_100 = *plStack_100 + -1, *plStack_100 == 0)) {
              (**(code **)(plStack_100[1] + 0x30))();
            }
          }
          plStack_100 = plVar14;
          FUN_23e8bba40(plVar7,&DAT_23ec5e2bc,plVar15);
          if (_DAT_23eede738 == plVar7) {
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            _DAT_23eede738 = (longlong *)0x0;
          }
          lVar13 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
          plVar14 = *(longlong **)(lVar13 + 0x28);
          plVar7 = (longlong *)plVar14[2];
          *(undefined8 *)(*(longlong *)(lVar9 + 0x38) + 8) = *(undefined8 *)(lVar13 + 0x30);
          *(undefined4 *)(plVar14 + 8) = 0xffffffff;
          if (plVar7 != (longlong *)0x0) {
            plVar14[2] = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
          }
          *plVar14 = *plVar14 + -1;
          if (*plVar14 == 0) {
            (**(code **)(plVar14[1] + 0x30))(plVar14);
          }
          plVar7 = plStack_100;
          auVar4 = auStack_110;
          uVar10 = auStack_110._0_8_;
          uVar17 = auStack_110._8_8_;
          plVar14[0xf] = 0;
          auStack_110 = (undefined1  [16])0x0;
          plStack_100 = (longlong *)0x0;
          if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          auStack_110 = auVar4;
          plStack_100 = plVar7;
          FUN_23a33aa70(lVar9,uVar10,uVar17,plVar7);
          return (longlong *)0x0;
        }
        *plVar7 = *plVar7 + 1;
        DAT_23ed6a4c0 = plVar7;
      }
      uStack_80 = uVar10;
      puStack_b0 = (undefined8 *)0x23e827302;
      plStack_88 = plVar8;
      lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_88);
      if (lVar9 == 0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        uVar21 = 0x3f;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *plVar12 = *plVar12 + -1;
        plVar7 = plStack_68;
        plVar11 = DAT_23ed6a4f8;
        if (*plVar12 == 0) {
          puStack_b0 = (undefined8 *)0x23e82745d;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
          plVar7 = plStack_68;
          plVar11 = DAT_23ed6a4f8;
        }
      }
      else {
        plVar12[4] = lVar9;
        puStack_b0 = (undefined8 *)0x23e82731c;
        plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar12);
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          puStack_b0 = (undefined8 *)0x23e82732f;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        pcVar3 = PyExc_FileNotFoundError_exref;
        if (plVar7 == (longlong *)0x0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plVar7 = *(longlong **)(param_1 + 0x70);
          uVar21 = 0x3f;
          *(undefined8 *)(param_1 + 0x70) = 0;
          *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
          plVar11 = DAT_23ed6a4f8;
        }
        else {
          *(undefined4 *)(plVar15 + 5) = 0x3f;
          puStack_b0 = (undefined8 *)0x23e827354;
          uVar10 = FUN_23e914090(param_1,*(undefined8 *)pcVar3,plVar7);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            puStack_b0 = (undefined8 *)0x23e827368;
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          auStack_78._0_8_ = uVar10;
          uVar21 = 0x3f;
          puStack_b0 = (undefined8 *)0x23e827380;
          FUN_23e91b7d0(param_1,auStack_78);
          plVar7 = plStack_68;
          plVar11 = DAT_23ed6a4f8;
        }
      }
      goto joined_r0x00023e82718c;
    }
  }
  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  plVar7 = *(longlong **)(param_1 + 0x70);
  uVar21 = 0x3e;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
  plVar11 = DAT_23ed6a4f8;
joined_r0x00023e82718c:
  DAT_23ed6a4f8 = plVar11;
  plStack_68 = plVar7;
  if (plVar7 == (longlong *)0x0) {
    if (plVar11 == (longlong *)0x0) {
      puStack_b0 = (undefined8 *)0x23e82755c;
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar3 = _PyRuntime_exref;
    plVar11[2] = 0;
    plVar11[3] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    lVar9 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar21;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar13 = plVar11[-1];
    puVar20 = *(undefined8 **)(lVar9 + 8);
    *puVar20 = plVar11 + -2;
    plVar11[-2] = lVar9;
    plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar20;
    *(longlong **)(lVar9 + 8) = plVar11 + -2;
    plVar7 = plVar11;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      puStack_b0 = (undefined8 *)0x23e82723d;
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else if ((longlong *)plVar7[3] != plVar15) {
    if (plVar11 == (longlong *)0x0) {
      puStack_b0 = (undefined8 *)0x23e8274ec;
      plVar11 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      DAT_23ed6a4f8 = (longlong *)*plVar11;
      *plVar11 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar3 = _PyRuntime_exref;
    plVar11[3] = (longlong)plVar15;
    *plVar15 = *plVar15 + 1;
    lVar9 = *(longlong *)(pcVar3 + 0x1f8);
    *(undefined4 *)(plVar11 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar11 + 0x24) = uVar21;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar13 = plVar11[-1];
    puVar20 = *(undefined8 **)(lVar9 + 8);
    *puVar20 = plVar11 + -2;
    plVar11[-2] = lVar9;
    plVar11[-1] = (ulonglong)((uint)lVar13 & 3) | (ulonglong)puVar20;
    *(longlong **)(lVar9 + 8) = plVar11 + -2;
    plVar11[2] = (longlong)plVar7;
    *plVar7 = *plVar7 + 1;
    plVar7 = plVar11;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      puStack_b0 = (undefined8 *)0x23e827017;
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
  plStack_68 = plVar7;
  puStack_b0 = (undefined8 *)0x23e827031;
  FUN_23e8bba40(plVar15,&DAT_23ec5e407,plVar14,plVar8);
  if (_DAT_23eede750 == plVar15) {
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      puStack_b0 = (undefined8 *)0x23e827150;
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    _DAT_23eede750 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar9 + 0x28);
  plVar15 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      puStack_b0 = (undefined8 *)0x23e827077;
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_b0 = (undefined8 *)0x23e827087;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar15 = plStack_68;
  plVar7[0xf] = 0;
  uVar10 = auStack_78._0_8_;
  uVar17 = auStack_78._8_8_;
  auStack_78 = (undefined1  [16])0x0;
  plStack_68 = (longlong *)0x0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    puStack_b0 = (undefined8 *)0x23e8270c1;
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  *plVar14 = *plVar14 + -1;
  plStack_68 = plVar15;
  auStack_78._0_8_ = uVar10;
  auStack_78._8_8_ = uVar17;
  if (*plVar14 == 0) {
    puStack_b0 = (undefined8 *)0x23e82712b;
    (**(code **)(plVar14[1] + 0x30))(plVar14);
  }
  puStack_b0 = (undefined8 *)0x23e8270ec;
  FUN_23a33aa70(param_1,auStack_78._0_8_,auStack_78._8_8_,plStack_68);
  return (longlong *)0x0;
}
