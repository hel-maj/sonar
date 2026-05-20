/* ===== 23e825840 workers.fishing.path_utils:10 ===== */
/* ghidra_name=FUN_23e825840 entry=23e825840 size=3964 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

longlong * FUN_23e825840(longlong param_1)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  code *pcVar4;
  code *pcVar5;
  undefined1 auVar6 [16];
  int iVar7;
  code *pcVar8;
  longlong lVar9;
  longlong *plVar10;
  longlong *plVar11;
  longlong *plVar12;
  undefined8 uVar13;
  longlong *plVar14;
  longlong lVar15;
  undefined8 uVar16;
  longlong *plVar17;
  undefined4 uVar18;
  undefined8 uStack_120;
  undefined8 uStack_118;
  longlong *plStack_110;
  longlong *plStack_f8;
  longlong *plStack_f0;
  code *pcStack_e8;
  longlong lStack_e0;
  undefined8 *puStack_d8;
  longlong *plStack_d0;
  longlong *plStack_a8;
  longlong *plStack_98;
  longlong **pplStack_90;
  longlong *plStack_88;
  undefined8 uStack_80;
  undefined1 auStack_78 [16];
  longlong *plStack_68;
  
  plVar17 = _DAT_23eede780;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if (_DAT_23eede780 == (longlong *)0x0) {
LAB_23e825891:
    plStack_d0 = (longlong *)0x23e8258ad;
    _DAT_23eede780 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eede770,DAT_23eede778,0x18);
  }
  else {
    lVar9 = *_DAT_23eede780;
    if (1 < lVar9) {
      *_DAT_23eede780 = lVar9 + -1;
      goto LAB_23e825891;
    }
    if (_DAT_23eede780[2] != 0) {
      *_DAT_23eede780 = lVar9 + -1;
      if (lVar9 + -1 == 0) {
        plStack_d0 = (longlong *)0x23e825d0a;
        (**(code **)(plVar17[1] + 0x30))(plVar17);
      }
      goto LAB_23e825891;
    }
  }
  plVar1 = _DAT_23eede780;
  lVar9 = *(longlong *)(param_1 + 0x38);
  plVar17 = _DAT_23eede780 + 9;
  lVar15 = *(longlong *)(lVar9 + 8);
  _DAT_23eede780[0xf] = lVar15;
  *(longlong **)(lVar9 + 8) = plVar17;
  if ((lVar15 != 0) &&
     (((*(char *)(lVar15 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar15 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar15 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar15 + 0x38))) && (plVar1[0xe] != 0)))) {
    plVar17 = *(longlong **)(lVar15 + 0x28);
    *(longlong **)(plVar1[0xe] + 0x10) = plVar17;
    if (plVar17 != (longlong *)0x0) {
      *plVar17 = *plVar17 + 1;
    }
  }
  plVar17 = &DAT_23ed6a210;
  *plVar1 = *plVar1 + 1;
  *(undefined4 *)(plVar1 + 8) = 0;
  if (DAT_23ed6a210 == 0) {
    plStack_d0 = (longlong *)0x23e825d4d;
    DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec5e349);
    if (DAT_23ed6a210 == 0) goto LAB_23e825d5d;
  }
  pcVar4 = _Py_FalseStruct_exref;
  plStack_d0 = (longlong *)0x23e825941;
  pcVar8 = (code *)FUN_23e8bbbe0(param_1,DAT_23ed6a210,_DAT_23eedcfe0,_Py_FalseStruct_exref);
  if (pcVar8 == (code *)0x0) {
    plStack_68 = *(longlong **)(param_1 + 0x70);
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x15;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e825db0;
  }
  plStack_d0 = (longlong *)0x23e825955;
  iVar7 = FUN_23a35f020(pcVar8);
  if (iVar7 == -1) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
    if (*(longlong *)pcVar8 == 0) {
      uVar18 = 0x15;
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      plStack_d0 = (longlong *)0x23e826124;
      (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
      pcVar8 = (code *)0x0;
    }
    else {
      uVar18 = 0x15;
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      pcVar8 = (code *)0x0;
    }
    goto LAB_23e825db0;
  }
  if (iVar7 != 1) {
    *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
    if (*(longlong *)pcVar8 == 0) {
      plStack_d0 = (longlong *)0x23e825973;
      (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
    }
    plStack_d0 = (longlong *)0x23e82598f;
    iVar7 = PySequence_Contains(DAT_23eedcfd0,DAT_23ed6cdd0);
    if (iVar7 == -1) {
      auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
      plStack_68 = *(longlong **)(param_1 + 0x70);
      plVar10 = (longlong *)0x0;
      plVar12 = (longlong *)0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      uVar18 = 0x15;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      pcVar8 = (code *)0x0;
      goto LAB_23e825db0;
    }
    pcVar8 = pcVar4;
    if (iVar7 == 1) {
      pcVar8 = _Py_TrueStruct_exref;
    }
    *(longlong *)pcVar8 = *(longlong *)pcVar8 + 1;
  }
  plStack_d0 = (longlong *)0x23e8259b2;
  iVar7 = FUN_23a35f020(pcVar8);
  if (iVar7 == -1) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x16;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e825db0;
  }
  if (iVar7 == 0) {
    plStack_d0 = (longlong *)0x23e825b7d;
    lVar9 = FUN_23e8dc0a0();
    if (lVar9 == 0) {
      plVar10 = (longlong *)0x0;
      uVar18 = 0x1f;
      plStack_d0 = (longlong *)0x23e8265bc;
      FUN_23e915740(param_1,auStack_78,DAT_23eedcfe8);
      plVar12 = (longlong *)0x0;
      goto LAB_23e825db0;
    }
    lVar15 = *(longlong *)(DAT_23eedcfd0 + 0x20);
    if (*(char *)(lVar15 + 10) == '\0') {
      plStack_d0 = (longlong *)0x23e8265e4;
      plVar12 = (longlong *)FUN_23a37a020(DAT_23eedcfd0,DAT_23ed6cd80);
      if (plVar12 == (longlong *)0x0) goto LAB_23e82604f;
      lVar15 = *plVar12;
LAB_23e8265f0:
      if (lVar15 == 0) goto LAB_23e82604f;
    }
    else {
      iVar7 = *(int *)(lVar15 + 0xc);
      if (*(int *)(lVar15 + 0xc) == 0) {
        *(int *)(lVar15 + 0xc) = _DAT_23ec15568;
        iVar7 = _DAT_23ec15568;
        _DAT_23ec15568 = _DAT_23ec15568 + 1;
      }
      if (_DAT_23ec1556c != iVar7) {
        plStack_d0 = (longlong *)0x23e825d31;
        _DAT_23ec1556c = iVar7;
        _DAT_23eede768 = FUN_23e8cbd60(lVar15,DAT_23ed6cd80,*(undefined8 *)(DAT_23ed6cd80 + 0x18));
      }
      if (-1 < _DAT_23eede768) {
        plVar12 = (longlong *)(lVar15 + 0x20 + (1L << (*(byte *)(lVar15 + 9) & 0x3f)));
        if (plVar12[_DAT_23eede768 * 2 + 1] != 0) goto LAB_23e825bf6;
        plStack_d0 = (longlong *)0x23e8266e0;
        plStack_98 = plVar12;
        _DAT_23eede768 = FUN_23e8cbd60(lVar15,DAT_23ed6cd80,*(undefined8 *)(DAT_23ed6cd80 + 0x18));
        if (-1 < _DAT_23eede768) {
          lVar15 = plStack_98[_DAT_23eede768 * 2 + 1];
          goto LAB_23e8265f0;
        }
      }
LAB_23e82604f:
      plStack_d0 = (longlong *)0x23e826066;
      plVar12 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23ed6cd80);
      if ((plVar12 == (longlong *)0x0) || (*plVar12 == 0)) {
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        uVar18 = 0x1f;
        plStack_d0 = (longlong *)0x23e826097;
        FUN_23e915740(param_1,auStack_78,DAT_23ed6cd80);
        goto LAB_23e825db0;
      }
    }
LAB_23e825bf6:
    *(undefined4 *)(plVar1 + 5) = 0x1f;
    plStack_d0 = (longlong *)0x23e825c08;
    plVar10 = (longlong *)FUN_23e914090(param_1,lVar9);
    plVar12 = (longlong *)0x0;
    if (plVar10 != (longlong *)0x0) {
      plStack_d0 = (longlong *)0x23e825c2b;
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6cfb0);
      *plVar10 = *plVar10 + -1;
      if (*plVar10 == 0) {
        plStack_d0 = (longlong *)0x23e825c3e;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
      }
      if (plVar12 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0x1f;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar10 = (longlong *)0x0;
        goto LAB_23e825db0;
      }
      plStack_d0 = (longlong *)0x23e825c57;
      plVar10 = (longlong *)FUN_23e8bc2f0(plVar12,DAT_23ed6cfb0);
      *plVar12 = *plVar12 + -1;
      if (*plVar12 == 0) {
        plStack_d0 = (longlong *)0x23e825c6f;
        plStack_98 = plVar10;
        (**(code **)(plVar12[1] + 0x30))(plVar12);
        plVar10 = plStack_98;
      }
      if (plVar10 == (longlong *)0x0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        plVar10 = (longlong *)0x0;
        plVar12 = (longlong *)0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        uVar18 = 0x1f;
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23e825db0;
      }
      plStack_d0 = (longlong *)0x23e825c92;
      plStack_98 = plVar10;
      plVar12 = (longlong *)FUN_23e8bc2f0(plVar10,DAT_23ed6cfb0);
      *plStack_98 = *plStack_98 + -1;
      if (*plStack_98 == 0) {
        plStack_d0 = (longlong *)0x23e825caa;
        (**(code **)(plStack_98[1] + 0x30))(plStack_98);
      }
      if (plVar12 != (longlong *)0x0) goto LAB_23e825a5d;
    }
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x1f;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e825db0;
  }
  plStack_d0 = (longlong *)0x23e8259c8;
  lVar9 = FUN_23e8dc0a0();
  if (lVar9 == 0) {
    plVar12 = (longlong *)0x0;
    uVar18 = 0x1a;
    plStack_d0 = (longlong *)0x23e826595;
    FUN_23e915740(param_1,auStack_78,DAT_23eedcfe8);
    plVar10 = (longlong *)0x0;
    goto LAB_23e825db0;
  }
  if (DAT_23ed6a210 == 0) {
    plStack_d0 = (longlong *)0x23e8264f5;
    DAT_23ed6a210 = PyImport_ImportModule(&DAT_23ec5e349);
    if (DAT_23ed6a210 == 0) {
      DAT_23ed6a210 = 0;
      goto LAB_23e825d5d;
    }
  }
  plStack_d0 = (longlong *)0x23e8259ed;
  plVar10 = (longlong *)FUN_23e8bc2f0(DAT_23ed6a210,_DAT_23eedcff0);
  plVar12 = (longlong *)0x0;
  if (plVar10 == (longlong *)0x0) {
LAB_23e826130:
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar10 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x1a;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e825db0;
  }
  *(undefined4 *)(plVar1 + 5) = 0x1a;
  plStack_d0 = (longlong *)0x23e825a0e;
  plVar11 = (longlong *)FUN_23e914090(param_1,lVar9,plVar10);
  *plVar10 = *plVar10 + -1;
  if (*plVar10 == 0) {
    plStack_d0 = (longlong *)0x23e825a21;
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  if (plVar11 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    plVar12 = (longlong *)0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    uVar18 = 0x1a;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    plVar10 = (longlong *)0x0;
    goto LAB_23e825db0;
  }
  plStack_d0 = (longlong *)0x23e825a41;
  plVar12 = (longlong *)FUN_23e8bc2f0(plVar11,DAT_23ed6cfb0);
  *plVar11 = *plVar11 + -1;
  if (*plVar11 == 0) {
    plStack_d0 = (longlong *)0x23e825a54;
    (**(code **)(plVar11[1] + 0x30))(plVar11);
  }
  if (plVar12 == (longlong *)0x0) goto LAB_23e826130;
LAB_23e825a5d:
  plStack_d0 = (longlong *)0x23e825a6c;
  plVar10 = (longlong *)FUN_23e8c6f80(plVar12,_DAT_23eedcff8);
  if (plVar10 == (longlong *)0x0) {
    auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
    plStack_68 = *(longlong **)(param_1 + 0x70);
    uVar18 = 0x21;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    goto LAB_23e825db0;
  }
  *(undefined4 *)(plVar1 + 5) = 0x23;
  plStack_d0 = (longlong *)0x23e825a92;
  plVar11 = (longlong *)FUN_23e91bfe0(param_1,plVar10,DAT_23ed6cee0);
  if (plVar11 != (longlong *)0x0) {
    plStack_d0 = (longlong *)0x23e825aa8;
    plStack_98 = plVar11;
    iVar7 = FUN_23a35f020(plVar11);
    *plStack_98 = *plStack_98 + -1;
    if (*plStack_98 == 0) {
      plVar11 = plStack_98 + 1;
      plStack_98 = (longlong *)CONCAT44(plStack_98._4_4_,iVar7);
      plStack_d0 = (longlong *)0x23e825abe;
      (**(code **)(*plVar11 + 0x30))();
      iVar7 = (int)plStack_98;
    }
    plVar11 = _DAT_23eedd000;
    if (iVar7 != -1) {
      if (iVar7 != 0) {
        lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar17 = *(longlong **)(lVar9 + 0x28);
        plVar1 = (longlong *)plVar17[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
        *(undefined4 *)(plVar17 + 8) = 0xffffffff;
        if (plVar1 != (longlong *)0x0) {
          plVar17[2] = 0;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            plStack_d0 = (longlong *)0x23e826467;
            (**(code **)(plVar1[1] + 0x30))();
          }
        }
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          plStack_d0 = (longlong *)0x23e825b19;
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        plVar17[0xf] = 0;
        *plVar10 = *plVar10 + 1;
        *(longlong *)pcVar8 = *(longlong *)pcVar8 + -1;
        if (*(longlong *)pcVar8 == 0) {
          plStack_d0 = (longlong *)0x23e825b35;
          (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
        }
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          plStack_d0 = (longlong *)0x23e825b45;
          (**(code **)(plVar12[1] + 0x30))(plVar12);
        }
        *plVar10 = *plVar10 + -1;
        if (*plVar10 != 0) {
          return plVar10;
        }
        plStack_d0 = (longlong *)0x23e825b55;
        (**(code **)(plVar10[1] + 0x30))(plVar10);
        return plVar10;
      }
      lVar9 = *(longlong *)(param_1 + 0x10);
      plVar14 = *(longlong **)(lVar9 + 0xe40);
      if (plVar14 == (longlong *)0x0) {
        plStack_98 = _DAT_23eedd000;
        plStack_d0 = (longlong *)0x23e8264d6;
        plVar14 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,6);
      }
      else {
        lVar15 = plVar14[3];
        *(int *)(lVar9 + 0xecc) = *(int *)(lVar9 + 0xecc) + -1;
        *(longlong *)(lVar9 + 0xe40) = lVar15;
        *plVar14 = 1;
        plStack_98 = plVar11;
      }
      pcVar5 = _PyRuntime_exref;
      plVar14[8] = 0;
      *(undefined1 (*) [16])(plVar14 + 4) = (undefined1  [16])0x0;
      lVar9 = *(longlong *)(pcVar5 + 0x1f8);
      *(undefined1 (*) [16])(plVar14 + 6) = (undefined1  [16])0x0;
      lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
      lVar15 = plVar14[-1];
      puVar2 = *(undefined8 **)(lVar9 + 8);
      *puVar2 = plVar14 + -2;
      plVar14[-2] = lVar9;
      plVar14[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar2;
      *(longlong **)(lVar9 + 8) = plVar14 + -2;
      plVar11 = DAT_23ed6a4c0;
      *plStack_98 = *plStack_98 + 1;
      plVar14[3] = (longlong)plStack_98;
      uVar13 = DAT_23ed6cd28;
      plStack_98 = plVar14;
      if (plVar11 == (longlong *)0x0) {
        plStack_d0 = (longlong *)0x23e82673d;
        plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
        if (plVar11 != (longlong *)0x0) {
          *plVar11 = *plVar11 + 1;
          DAT_23ed6a4c0 = plVar11;
          goto LAB_23e8262a5;
        }
LAB_23e826837:
        plStack_d0 = (longlong *)0x23e82683f;
        PyErr_PrintEx(0);
        lVar9 = 1;
        plStack_d0 = (longlong *)0x23e82684a;
        Py_Exit();
        plVar12 = _DAT_23eede760;
        puStack_d8 = &DAT_23ed6cce0;
        plStack_f8 = plVar1;
        plStack_f0 = plVar10;
        pcStack_e8 = pcVar8;
        lStack_e0 = param_1;
        plStack_d0 = plVar17;
        if (_DAT_23eede760 != (longlong *)0x0) {
          lVar15 = *_DAT_23eede760;
          if (lVar15 < 2) {
            if (_DAT_23eede760[2] == 0) goto LAB_23e8268a6;
            *_DAT_23eede760 = lVar15 + -1;
            if (lVar15 + -1 == 0) {
              (**(code **)(plVar12[1] + 0x30))(plVar12);
            }
          }
          else {
            *_DAT_23eede760 = lVar15 + -1;
          }
        }
        _DAT_23eede760 = (longlong *)FUN_23e91f3b0(lVar9,DAT_23eede758,DAT_23eede778,0);
LAB_23e8268a6:
        plVar1 = _DAT_23eede760;
        lVar15 = *(longlong *)(lVar9 + 0x38);
        plVar17 = _DAT_23eede760 + 9;
        lVar3 = *(longlong *)(lVar15 + 8);
        _DAT_23eede760[0xf] = lVar3;
        *(longlong **)(lVar15 + 8) = plVar17;
        if (((lVar3 != 0) &&
            ((*(char *)(lVar3 + 0x45) == '\x01' ||
             ((ulonglong)
              (*(longlong *)(lVar3 + 0x20) + 0xb8 +
              (longlong)*(int *)(*(longlong *)(lVar3 + 0x20) + 0xa8) * 2) <=
              *(ulonglong *)(lVar3 + 0x38))))) && (plVar1[0xe] != 0)) {
          plVar17 = *(longlong **)(lVar3 + 0x28);
          *(longlong **)(plVar1[0xe] + 0x10) = plVar17;
          if (plVar17 != (longlong *)0x0) {
            *plVar17 = *plVar17 + 1;
          }
        }
        *plVar1 = *plVar1 + 1;
        *(undefined4 *)(plVar1 + 8) = 0;
        lVar15 = FUN_23e8dc1d0();
        if (lVar15 == 0) {
          FUN_23e915740(lVar9,&uStack_120,DAT_23eedd020);
          uVar13 = uStack_120;
          uVar16 = uStack_118;
          plVar17 = plStack_110;
        }
        else {
          *(undefined4 *)(plVar1 + 5) = 0x2f;
          plVar17 = (longlong *)FUN_23e91a870(lVar9,lVar15);
          if (plVar17 != (longlong *)0x0) {
            plVar12 = (longlong *)FUN_23e8c6f80(plVar17,_DAT_23eedd028);
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if (plVar12 != (longlong *)0x0) {
              lVar15 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
              plVar17 = *(longlong **)(lVar15 + 0x28);
              plVar1 = (longlong *)plVar17[2];
              *(undefined8 *)(*(longlong *)(lVar9 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
              *(undefined4 *)(plVar17 + 8) = 0xffffffff;
              if (plVar1 != (longlong *)0x0) {
                plVar17[2] = 0;
                *plVar1 = *plVar1 + -1;
                if (*plVar1 == 0) {
                  (**(code **)(plVar1[1] + 0x30))();
                }
              }
              *plVar17 = *plVar17 + -1;
              if (*plVar17 == 0) {
                (**(code **)(plVar17[1] + 0x30))(plVar17);
              }
              plVar17[0xf] = 0;
              return plVar12;
            }
          }
          plVar17 = *(longlong **)(lVar9 + 0x70);
          *(undefined8 *)(lVar9 + 0x70) = 0;
          uVar13 = *(undefined8 *)(lVar9 + 0x60);
          *(undefined1 (*) [16])(lVar9 + 0x60) = (undefined1  [16])0x0;
          uVar16 = *(undefined8 *)(lVar9 + 0x68);
        }
        plVar12 = DAT_23ed6a4f8;
        if (plVar17 == (longlong *)0x0) {
          if (DAT_23ed6a4f8 == (longlong *)0x0) {
            plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
          }
          else {
            plVar17 = (longlong *)*DAT_23ed6a4f8;
            *DAT_23ed6a4f8 = 1;
            DAT_23ed6a4f8 = plVar17;
            DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
          }
          plVar12[2] = 0;
          plVar12[3] = (longlong)plVar1;
          *plVar1 = *plVar1 + 1;
          plVar12[4] = 0x2fffffffff;
          lVar15 = *(longlong *)
                    (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
          lVar3 = plVar12[-1];
          puVar2 = *(undefined8 **)(lVar15 + 8);
          *puVar2 = plVar12 + -2;
          plVar12[-2] = lVar15;
          plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar15 + 8) = plVar12 + -2;
          plVar10 = plVar12;
        }
        else {
          plVar10 = plVar17;
          if ((longlong *)plVar17[3] != plVar1) {
            if (DAT_23ed6a4f8 == (longlong *)0x0) {
              plVar12 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
            }
            else {
              plVar10 = (longlong *)*DAT_23ed6a4f8;
              *DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = plVar10;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
            }
            plVar12[3] = (longlong)plVar1;
            *plVar1 = *plVar1 + 1;
            plVar12[4] = 0x2fffffffff;
            lVar15 = *(longlong *)
                      (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
            lVar3 = plVar12[-1];
            puVar2 = *(undefined8 **)(lVar15 + 8);
            *puVar2 = plVar12 + -2;
            plVar12[-2] = lVar15;
            plVar12[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar2;
            lVar3 = *plVar17;
            *(longlong **)(lVar15 + 8) = plVar12 + -2;
            plVar12[2] = (longlong)plVar17;
            plVar10 = plVar12;
            if (lVar3 == 0) {
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
          }
        }
        FUN_23e8bba40(plVar1,0);
        if (_DAT_23eede760 == plVar1) {
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          _DAT_23eede760 = (longlong *)0x0;
        }
        lVar15 = *(longlong *)(*(longlong *)(lVar9 + 0x38) + 8);
        plVar17 = *(longlong **)(lVar15 + 0x28);
        plVar1 = (longlong *)plVar17[2];
        *(undefined8 *)(*(longlong *)(lVar9 + 0x38) + 8) = *(undefined8 *)(lVar15 + 0x30);
        *(undefined4 *)(plVar17 + 8) = 0xffffffff;
        if (plVar1 != (longlong *)0x0) {
          plVar17[2] = 0;
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))();
          }
        }
        *plVar17 = *plVar17 + -1;
        if (*plVar17 == 0) {
          (**(code **)(plVar17[1] + 0x30))(plVar17);
        }
        plVar17[0xf] = 0;
        FUN_23a33aa70(lVar9,uVar13,uVar16,plVar10);
        return (longlong *)0x0;
      }
LAB_23e8262a5:
      pplStack_90 = &plStack_88;
      uStack_80 = uVar13;
      plStack_d0 = (longlong *)0x23e8262c4;
      plStack_88 = plVar10;
      lVar9 = FUN_23e94ed00(param_1,plVar11,pplStack_90);
      if (lVar9 == 0) {
        auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
        plStack_68 = *(longlong **)(param_1 + 0x70);
        uVar18 = 0x25;
      }
      else {
        plStack_98[4] = lVar9;
        plVar11 = _DAT_23eedd008;
        *_DAT_23eedd008 = *_DAT_23eedd008 + 1;
        plStack_98[5] = (longlong)plVar11;
        uVar13 = DAT_23ed6cd28;
        if (DAT_23ed6a4c0 == (longlong *)0x0) {
          plStack_d0 = (longlong *)0x23e82677d;
          plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          if (plVar11 == (longlong *)0x0) goto LAB_23e826837;
          *plVar11 = *plVar11 + 1;
          DAT_23ed6a4c0 = plVar11;
        }
        uStack_80 = uVar13;
        plStack_d0 = (longlong *)0x23e82631a;
        plStack_88 = plVar12;
        lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_90);
        if (lVar9 == 0) {
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uVar18 = 0x26;
        }
        else {
          plStack_98[6] = lVar9;
          plVar17 = _DAT_23eedd010;
          lVar9 = DAT_23ed6a210;
          *_DAT_23eedd010 = *_DAT_23eedd010 + 1;
          plStack_98[7] = (longlong)plVar17;
          if (lVar9 == 0) {
            plStack_d0 = (longlong *)0x23e8267b3;
            lVar9 = PyImport_ImportModule(&DAT_23ec5e349);
            DAT_23ed6a210 = lVar9;
            if (lVar9 == 0) {
              DAT_23ed6a210 = 0;
LAB_23e825d5d:
              plStack_d0 = (longlong *)0x23e825d77;
              FUN_23e9364c0("%s : %s\n","IMPORT_HARD_SYS",
                            "\"Unexpected failure of hard import of \'sys\'\"");
                    /* WARNING: Subroutine does not return */
              plStack_d0 = (longlong *)0x23e825d7c;
              abort();
            }
          }
          plStack_d0 = (longlong *)0x23e82635f;
          plVar17 = (longlong *)FUN_23e8bbbe0(param_1,lVar9,_DAT_23eedcfe0,pcVar4);
          uVar13 = DAT_23ed6cd28;
          if (plVar17 != (longlong *)0x0) {
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plStack_d0 = (longlong *)0x23e826817;
              plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar11 == (longlong *)0x0) goto LAB_23e826837;
              *plVar11 = *plVar11 + 1;
              DAT_23ed6a4c0 = plVar11;
            }
            uStack_80 = uVar13;
            plStack_d0 = (longlong *)0x23e8263a5;
            plStack_88 = plVar17;
            lVar9 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,pplStack_90);
            *plVar17 = *plVar17 + -1;
            if (*plVar17 == 0) {
              plStack_d0 = (longlong *)0x23e8263be;
              (**(code **)(plVar17[1] + 0x30))(plVar17);
            }
            if (lVar9 != 0) {
              plStack_98[8] = lVar9;
              plStack_d0 = (longlong *)0x23e8263e3;
              plVar17 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plStack_98);
              *plStack_98 = *plStack_98 + -1;
              if (*plStack_98 == 0) {
                plStack_d0 = (longlong *)0x23e8263fb;
                (**(code **)(plStack_98[1] + 0x30))(plStack_98);
              }
              pcVar4 = PyExc_FileNotFoundError_exref;
              if (plVar17 == (longlong *)0x0) {
                auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
                plStack_68 = *(longlong **)(param_1 + 0x70);
                uVar18 = 0x25;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                *(undefined4 *)(plVar1 + 5) = 0x24;
                plStack_d0 = (longlong *)0x23e826420;
                uVar13 = FUN_23e914090(param_1,*(undefined8 *)pcVar4,plVar17);
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  plStack_d0 = (longlong *)0x23e826435;
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                auStack_78._0_8_ = uVar13;
                uVar18 = 0x24;
                plStack_d0 = (longlong *)0x23e82644d;
                FUN_23e91b7d0(param_1,auStack_78);
              }
              goto LAB_23e825db0;
            }
          }
          auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
          plStack_68 = *(longlong **)(param_1 + 0x70);
          uVar18 = 0x27;
        }
      }
      *(undefined8 *)(param_1 + 0x70) = 0;
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *plStack_98 = *plStack_98 + -1;
      if (*plStack_98 == 0) {
        plStack_d0 = (longlong *)0x23e826695;
        (**(code **)(plStack_98[1] + 0x30))(plStack_98);
      }
      goto LAB_23e825db0;
    }
  }
  auStack_78 = *(undefined1 (*) [16])(param_1 + 0x60);
  plStack_68 = *(longlong **)(param_1 + 0x70);
  uVar18 = 0x23;
  *(undefined8 *)(param_1 + 0x70) = 0;
  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
LAB_23e825db0:
  plVar11 = plStack_68;
  plVar17 = DAT_23ed6a4f8;
  if (plStack_68 == (longlong *)0x0) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plStack_d0 = (longlong *)0x23e826644;
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar11 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar11;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar17[2] = 0;
    plVar17[3] = (longlong)plVar1;
    *plVar1 = *plVar1 + 1;
    lVar9 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    lVar9 = *(longlong *)(lVar9 + 0x10);
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar18;
    lVar9 = *(longlong *)(lVar9 + 0x2e8);
    lVar15 = plVar17[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar17 + -2;
    plVar17[-2] = lVar9;
    plVar17[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar17 + -2;
    plVar11 = plVar17;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      plStack_d0 = (longlong *)0x23e82603c;
      (**(code **)(plStack_68[1] + 0x30))(plStack_68);
    }
  }
  else if ((longlong *)plStack_68[3] != plVar1) {
    if (DAT_23ed6a4f8 == (longlong *)0x0) {
      plStack_d0 = (longlong *)0x23e8261a4;
      plVar17 = (longlong *)FUN_23a33a530(PyTraceBack_Type_exref);
    }
    else {
      plVar14 = (longlong *)*DAT_23ed6a4f8;
      *DAT_23ed6a4f8 = 1;
      DAT_23ed6a4f8 = plVar14;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
    }
    pcVar4 = _PyRuntime_exref;
    plVar17[3] = (longlong)plVar1;
    *plVar1 = *plVar1 + 1;
    lVar9 = *(longlong *)(pcVar4 + 0x1f8);
    *(undefined4 *)(plVar17 + 4) = 0xffffffff;
    *(undefined4 *)((longlong)plVar17 + 0x24) = uVar18;
    lVar9 = *(longlong *)(*(longlong *)(lVar9 + 0x10) + 0x2e8);
    lVar15 = plVar17[-1];
    puVar2 = *(undefined8 **)(lVar9 + 8);
    *puVar2 = plVar17 + -2;
    plVar17[-2] = lVar9;
    plVar17[-1] = (ulonglong)((uint)lVar15 & 3) | (ulonglong)puVar2;
    *(longlong **)(lVar9 + 8) = plVar17 + -2;
    plVar17[2] = (longlong)plVar11;
    *plVar11 = *plVar11 + 1;
    plVar11 = plVar17;
    if ((plStack_68 != (longlong *)0x0) && (*plStack_68 = *plStack_68 + -1, *plStack_68 == 0)) {
      plStack_d0 = (longlong *)0x23e825e67;
      (**(code **)(plStack_68[1] + 0x30))();
    }
  }
  plStack_68 = plVar11;
  plStack_d0 = (longlong *)0x23e825e86;
  plStack_a8 = plVar10;
  FUN_23e8bba40(plVar1,&DAT_23ec5e2be,pcVar8,plVar12);
  if (_DAT_23eede780 == plVar1) {
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      plStack_d0 = (longlong *)0x23e825f80;
      (**(code **)(plVar1[1] + 0x30))(plVar1);
    }
    _DAT_23eede780 = (longlong *)0x0;
  }
  lVar9 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar17 = *(longlong **)(lVar9 + 0x28);
  plVar1 = (longlong *)plVar17[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar9 + 0x30);
  *(undefined4 *)(plVar17 + 8) = 0xffffffff;
  if (plVar1 != (longlong *)0x0) {
    plVar17[2] = 0;
    *plVar1 = *plVar1 + -1;
    if (*plVar1 == 0) {
      plStack_d0 = (longlong *)0x23e825ecc;
      (**(code **)(plVar1[1] + 0x30))();
    }
  }
  *plVar17 = *plVar17 + -1;
  if (*plVar17 == 0) {
    plStack_d0 = (longlong *)0x23e825edc;
    (**(code **)(plVar17[1] + 0x30))(plVar17);
  }
  plVar1 = plStack_68;
  auVar6 = auStack_78;
  uVar13 = auStack_78._0_8_;
  uVar16 = auStack_78._8_8_;
  plVar17[0xf] = 0;
  plStack_68 = (longlong *)0x0;
  auStack_78 = (undefined1  [16])0x0;
  if ((pcVar8 != (code *)0x0) &&
     (*(longlong *)pcVar8 = *(longlong *)pcVar8 + -1, *(longlong *)pcVar8 == 0)) {
    plStack_d0 = (longlong *)0x23e825f23;
    (**(code **)(*(longlong *)(pcVar8 + 8) + 0x30))(pcVar8);
  }
  if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
    plStack_d0 = (longlong *)0x23e825f38;
    (**(code **)(plVar12[1] + 0x30))(plVar12);
  }
  if ((plVar10 != (longlong *)0x0) && (*plVar10 = *plVar10 + -1, *plVar10 == 0)) {
    plStack_d0 = (longlong *)0x23e825f4d;
    (**(code **)(plVar10[1] + 0x30))(plVar10);
  }
  plStack_d0 = (longlong *)0x23e825f6a;
  auStack_78 = auVar6;
  plStack_68 = plVar1;
  FUN_23a33aa70(param_1,uVar13,uVar16,plVar1);
  return (longlong *)0x0;
}
