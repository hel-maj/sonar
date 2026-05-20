/* ===== 23e2c5dd0 ui.home_tab:284 ===== */
/* ghidra_name=FUN_23e2c5dd0 entry=23e2c5dd0 size=2620 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

code * FUN_23e2c5dd0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  undefined8 *puVar2;
  longlong lVar3;
  undefined4 uVar4;
  char cVar5;
  int iVar6;
  longlong *plVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong lVar10;
  longlong *plVar11;
  code *pcVar12;
  longlong *plVar13;
  longlong lVar14;
  longlong *plVar15;
  longlong *plVar16;
  longlong *plVar17;
  code *pcVar18;
  code *pcVar19;
  longlong lVar20;
  undefined4 uVar21;
  undefined1 auVar22 [8];
  undefined8 uVar23;
  longlong *plVar24;
  longlong *plStack_1e0;
  longlong *plStack_1d8;
  longlong *plStack_1d0;
  longlong *plStack_1c8;
  longlong *plStack_1c0;
  longlong *plStack_1b8;
  longlong *plStack_1b0;
  longlong *plStack_1a8;
  longlong *plStack_1a0;
  longlong *plStack_198;
  longlong **pplStack_190;
  longlong *plStack_170;
  code *pcStack_168;
  undefined1 auStack_160 [16];
  code *apcStack_150 [2];
  longlong *plStack_140;
  code *pcStack_138;
  code *pcStack_130;
  undefined1 auStack_120 [8];
  code *pcStack_118;
  code *pcStack_110;
  longlong *plStack_100;
  code *pcStack_f8;
  longlong *plStack_e8;
  longlong lStack_e0;
  longlong *plStack_d8;
  longlong *plStack_d0;
  longlong *plStack_c8;
  undefined8 *puStack_c0;
  longlong *plStack_b8;
  undefined8 *puStack_b0;
  code *pcStack_88;
  undefined4 uStack_7c;
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar7 = _DAT_23eeb02f8;
  plVar13 = (longlong *)*param_3;
  plVar1 = (longlong *)param_3[1];
  if (_DAT_23eeb02f8 == (longlong *)0x0) {
LAB_23e2c5e13:
    puStack_b0 = (undefined8 *)0x23e2c5e2f;
    _DAT_23eeb02f8 = (longlong *)FUN_23e91f3b0(param_1,DAT_23eeb02f0,DAT_23eeb0380,0x10);
  }
  else {
    lVar10 = *_DAT_23eeb02f8;
    if (1 < lVar10) {
      *_DAT_23eeb02f8 = lVar10 + -1;
      goto LAB_23e2c5e13;
    }
    if (_DAT_23eeb02f8[2] != 0) {
      *_DAT_23eeb02f8 = lVar10 + -1;
      if (lVar10 + -1 == 0) {
        puStack_b0 = (undefined8 *)0x23e2c6402;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      goto LAB_23e2c5e13;
    }
  }
  plVar15 = _DAT_23eeb02f8;
  lVar10 = *(longlong *)(param_1 + 0x38);
  plVar7 = _DAT_23eeb02f8 + 9;
  lVar14 = *(longlong *)(lVar10 + 8);
  _DAT_23eeb02f8[0xf] = lVar14;
  *(longlong **)(lVar10 + 8) = plVar7;
  if ((lVar14 != 0) &&
     (((*(char *)(lVar14 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar14 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar14 + 0x20) + 0xa8) * 2) <=
        *(ulonglong *)(lVar14 + 0x38))) && (plVar15[0xe] != 0)))) {
    plVar7 = *(longlong **)(lVar14 + 0x28);
    *(longlong **)(plVar15[0xe] + 0x10) = plVar7;
    if (plVar7 != (longlong *)0x0) {
      *plVar7 = *plVar7 + 1;
    }
  }
  lVar14 = DAT_23eeae258;
  *plVar15 = *plVar15 + 1;
  *(undefined4 *)(plVar15 + 8) = 0;
  lVar10 = *(longlong *)(lVar14 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    puStack_b0 = (undefined8 *)0x23e2c66a4;
    plVar7 = (longlong *)FUN_23a37a020(lVar14,DAT_23eeadce0);
    if (plVar7 == (longlong *)0x0) goto LAB_23e2c6221;
    lVar14 = *plVar7;
LAB_23e2c66b0:
    if (lVar14 == 0) goto LAB_23e2c6221;
  }
  else {
    iVar6 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = _DAT_23ec14e6c;
      iVar6 = _DAT_23ec14e6c;
      _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
    }
    if (_DAT_23ec14e5c != iVar6) {
      puStack_b0 = (undefined8 *)0x23e2c6211;
      _DAT_23ec14e5c = iVar6;
      _DAT_23eeb02e0 = FUN_23e8cbd60(lVar10,DAT_23eeadce0,*(undefined8 *)(DAT_23eeadce0 + 0x18));
    }
    if (-1 < _DAT_23eeb02e0) {
      lVar20 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar14 = *(longlong *)(lVar20 + 8 + _DAT_23eeb02e0 * 0x10);
      if (lVar14 != 0) goto LAB_23e2c5f03;
      puStack_b0 = (undefined8 *)0x23e2c678b;
      _DAT_23eeb02e0 = FUN_23e8cbd60(lVar10,DAT_23eeadce0,*(undefined8 *)(DAT_23eeadce0 + 0x18));
      if (-1 < _DAT_23eeb02e0) {
        lVar14 = *(longlong *)(lVar20 + 8 + _DAT_23eeb02e0 * 0x10);
        goto LAB_23e2c66b0;
      }
    }
LAB_23e2c6221:
    puStack_b0 = (undefined8 *)0x23e2c6237;
    plVar7 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeadce0);
    if ((plVar7 == (longlong *)0x0) || (lVar14 = *plVar7, lVar14 == 0)) {
      puStack_b0 = (undefined8 *)0x23e2c625c;
      FUN_23e915740(param_1,&plStack_78,DAT_23eeadce0);
      pcVar12 = DAT_23ed6a4f8;
      pcStack_88 = pcStack_70;
      uVar4 = uStack_7c;
      uVar21 = 0x11e;
      plVar8 = plStack_78;
      pcVar19 = pcStack_68;
      goto joined_r0x00023e2c64ac;
    }
  }
LAB_23e2c5f03:
  puStack_b0 = (undefined8 *)0x23e2c5f0f;
  plVar7 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eeadce8);
  if (plVar7 == (longlong *)0x0) {
LAB_23e2c65a0:
    pcStack_88 = *(code **)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcVar12 = DAT_23ed6a4f8;
    uVar4 = uStack_7c;
    uVar21 = 0x11e;
    goto joined_r0x00023e2c64ac;
  }
  lVar10 = *(longlong *)(DAT_23eeae258 + 0x20);
  if (*(char *)(lVar10 + 10) == '\0') {
    puStack_b0 = (undefined8 *)0x23e2c66cc;
    plVar8 = (longlong *)FUN_23a37a020(DAT_23eeae258,DAT_23eeadcf0);
    if (plVar8 == (longlong *)0x0) goto LAB_23e2c6439;
    lVar14 = *plVar8;
LAB_23e2c66d8:
    if (lVar14 == 0) goto LAB_23e2c6439;
LAB_23e2c5f8c:
    *(undefined4 *)(plVar15 + 5) = 0x11e;
    puStack_b0 = (undefined8 *)0x23e2c5f9e;
    plVar8 = (longlong *)FUN_23e914090(param_1,lVar14,plVar1);
    if (plVar8 == (longlong *)0x0) {
      pcStack_88 = *(code **)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcStack_68 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      goto LAB_23e2c6488;
    }
    *(undefined4 *)(plVar15 + 5) = 0x11e;
    puStack_b0 = (undefined8 *)0x23e2c5fbf;
    plVar9 = (longlong *)FUN_23e914090(param_1,plVar7,plVar8);
    *plVar7 = *plVar7 + -1;
    if (*plVar7 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c5fd2;
      (**(code **)(plVar7[1] + 0x30))(plVar7);
    }
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c5fe3;
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    if (plVar9 == (longlong *)0x0) goto LAB_23e2c65a0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c5ffc;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    puStack_b0 = (undefined8 *)0x23e2c6001;
    lVar10 = FUN_23e8f6a70();
    if (lVar10 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c6754;
      FUN_23e915740(param_1,&plStack_78,DAT_23eeadcf8);
      pcVar12 = DAT_23ed6a4f8;
      pcStack_88 = pcStack_70;
      uVar4 = uStack_7c;
      uVar21 = 0x11f;
      plVar8 = plStack_78;
      pcVar19 = pcStack_68;
      goto joined_r0x00023e2c64ac;
    }
    puStack_b0 = (undefined8 *)0x23e2c6019;
    plVar9 = (longlong *)FUN_23e8bc2f0(lVar10,_DAT_23eeadd00);
    plVar8 = _DAT_23eeadd08;
    if (plVar9 == (longlong *)0x0) {
LAB_23e2c65f0:
      pcStack_88 = *(code **)(param_1 + 0x68);
      plVar8 = *(longlong **)(param_1 + 0x60);
      pcVar19 = *(code **)(param_1 + 0x70);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcVar12 = DAT_23ed6a4f8;
      uVar4 = uStack_7c;
      uVar21 = 0x11f;
      goto joined_r0x00023e2c64ac;
    }
    lVar10 = *(longlong *)(param_1 + 0x10);
    plVar7 = *(longlong **)(lVar10 + 0xe20);
    if (plVar7 == (longlong *)0x0) {
      puStack_b0 = (undefined8 *)0x23e2c65e1;
      plVar7 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
    }
    else {
      lVar14 = plVar7[3];
      *(int *)(lVar10 + 0xebc) = *(int *)(lVar10 + 0xebc) + -1;
      *(longlong *)(lVar10 + 0xe20) = lVar14;
      *plVar7 = 1;
    }
    pcVar19 = _PyRuntime_exref;
    plVar7[4] = 0;
    lVar10 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
    lVar14 = plVar7[-1];
    plVar24 = *(longlong **)(lVar10 + 8);
    *plVar24 = (longlong)(plVar7 + -2);
    plVar7[-2] = lVar10;
    plVar7[-1] = (ulonglong)((uint)lVar14 & 3) | (ulonglong)plVar24;
    *(longlong **)(lVar10 + 8) = plVar7 + -2;
    plVar11 = DAT_23ed6a4c0;
    *plVar8 = *plVar8 + 1;
    plVar7[3] = (longlong)plVar8;
    pcVar19 = DAT_23ed6cd28;
    if (plVar11 == (longlong *)0x0) {
      puStack_b0 = (undefined8 *)0x23e2c6707;
      plVar11 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
      if (plVar11 == (longlong *)0x0) {
        puStack_b0 = (undefined8 *)0x23e2c685c;
        PyErr_PrintEx(0,0);
        lVar10 = 1;
        puStack_b0 = (undefined8 *)0x23e2c6867;
        Py_Exit();
        plVar8 = _DAT_23eeb02d8;
        puStack_b0 = &DAT_23ed6a4c0;
        puStack_c0 = &DAT_23ed6cce0;
        pcStack_f8 = pcVar19;
        plVar24 = (longlong *)*plVar24;
        pcStack_110 = (code *)0x0;
        auStack_120 = (undefined1  [8])0x0;
        pcStack_118 = (code *)0x0;
        plStack_100 = plVar1;
        plStack_e8 = plVar15;
        lStack_e0 = param_1;
        plStack_d8 = plVar7;
        plStack_d0 = plVar1;
        plStack_c8 = plVar13;
        plStack_b8 = plVar9;
        if (_DAT_23eeb02d8 == (longlong *)0x0) {
LAB_23e2c68d5:
          _DAT_23eeb02d8 = (longlong *)FUN_23e91f3b0(lVar10,DAT_23eeb02d0,DAT_23eeb0380,0x78);
        }
        else {
          lVar14 = *_DAT_23eeb02d8;
          if (1 < lVar14) {
            *_DAT_23eeb02d8 = lVar14 + -1;
            goto LAB_23e2c68d5;
          }
          if (_DAT_23eeb02d8[2] != 0) {
            *_DAT_23eeb02d8 = lVar14 + -1;
            if (lVar14 + -1 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            goto LAB_23e2c68d5;
          }
        }
        plVar1 = _DAT_23eeb02d8;
        lVar14 = *(longlong *)(lVar10 + 0x38);
        plVar13 = _DAT_23eeb02d8 + 9;
        lVar20 = *(longlong *)(lVar14 + 8);
        _DAT_23eeb02d8[0xf] = lVar20;
        *(longlong **)(lVar14 + 8) = plVar13;
        if ((lVar20 != 0) &&
           (((*(char *)(lVar20 + 0x45) == '\x01' ||
             ((ulonglong)
              (*(longlong *)(lVar20 + 0x20) + 0xb8 +
              (longlong)*(int *)(*(longlong *)(lVar20 + 0x20) + 0xa8) * 2) <=
              *(ulonglong *)(lVar20 + 0x38))) && (plVar1[0xe] != 0)))) {
          plVar13 = *(longlong **)(lVar20 + 0x28);
          *(longlong **)(plVar1[0xe] + 0x10) = plVar13;
          if (plVar13 != (longlong *)0x0) {
            *plVar13 = *plVar13 + 1;
          }
        }
        *plVar1 = *plVar1 + 1;
        uVar23 = _DAT_23eead900;
        *(undefined4 *)(plVar1 + 8) = 0;
        plVar13 = (longlong *)FUN_23e8bc2f0(plVar24,uVar23);
        if (plVar13 == (longlong *)0x0) {
LAB_23e2c6e40:
          pcStack_110 = *(code **)(lVar10 + 0x70);
          auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
          pcStack_118 = *(code **)(lVar10 + 0x68);
          iVar6 = 0x125;
          *(undefined8 *)(lVar10 + 0x70) = 0;
          *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
          goto LAB_23e2c6e6f;
        }
        plVar7 = (longlong *)FUN_23e8bc2f0(plVar13,_DAT_23eeadd18);
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          (**(code **)(plVar13[1] + 0x30))();
        }
        if (plVar7 == (longlong *)0x0) goto LAB_23e2c6e40;
        iVar6 = FUN_23a35f020();
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          (**(code **)(plVar7[1] + 0x30))();
        }
        if (iVar6 == -1) goto LAB_23e2c6e40;
        if (iVar6 == 0) {
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
          lVar14 = _DAT_23eeadd20;
          if (plVar13 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x126;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
          }
          else {
            *(undefined4 *)(plVar1 + 5) = 0x126;
            plVar7 = (longlong *)
                     FUN_23e915840(lVar10,plVar13,_DAT_23eeada60,*(undefined8 *)(lVar14 + 0x18));
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            if (plVar7 == (longlong *)0x0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plStack_1a0 = (longlong *)0x0;
              plVar13 = (longlong *)0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              iVar6 = 0x126;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              plStack_1e0 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              plVar15 = (longlong *)0x0;
              pcStack_118 = *(code **)(lVar10 + 0x68);
            }
            else {
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))(plVar7);
              }
              plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
              if (plVar7 == (longlong *)0x0) goto LAB_23e2c9158;
              plVar13 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eead9b8);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))();
              }
              plVar7 = _DAT_23eeadca8;
              if (plVar13 != (longlong *)0x0) {
                lVar14 = *(longlong *)(lVar10 + 0x10);
                pcVar19 = *(code **)(lVar14 + 0xe28);
                if (pcVar19 == (code *)0x0) {
                  pcVar19 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
                }
                else {
                  lVar20 = *(longlong *)(pcVar19 + 0x18);
                  *(int *)(lVar14 + 0xec0) = *(int *)(lVar14 + 0xec0) + -1;
                  *(longlong *)(lVar14 + 0xe28) = lVar20;
                  *(longlong *)pcVar19 = 1;
                }
                pcVar12 = _PyRuntime_exref;
                *(undefined1 (*) [16])(pcVar19 + 0x20) = (undefined1  [16])0x0;
                lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8)
                ;
                lVar20 = *(longlong *)(pcVar19 + -8);
                puVar2 = *(undefined8 **)(lVar14 + 8);
                *puVar2 = pcVar19 + -0x10;
                *(longlong *)(pcVar19 + -0x10) = lVar14;
                *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
                *(code **)(lVar14 + 8) = pcVar19 + -0x10;
                *plVar7 = *plVar7 + 1;
                *(longlong **)(pcVar19 + 0x18) = plVar7;
                plVar8 = (longlong *)FUN_23e8f6530();
                if (plVar8 == (longlong *)0x0) {
                  FUN_23e915740(lVar10,auStack_120,DAT_23eeadd28);
                  goto LAB_23e2c9379;
                }
                plVar7 = (longlong *)&DAT_23ed6a4c0;
                plVar15 = DAT_23ed6a4c0;
                pcVar12 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 == (longlong *)0x0) goto LAB_23e2c9573;
                goto LAB_23e2c6b42;
              }
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plStack_1a0 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              iVar6 = 0x127;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              plStack_1e0 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              pcStack_118 = *(code **)(lVar10 + 0x68);
            }
          }
LAB_23e2c6ef9:
          pcVar19 = pcStack_110;
          auStack_160._8_8_ = pcStack_118;
          auStack_160._0_8_ = auStack_120;
          pcStack_110 = (code *)0x0;
          auStack_120 = (undefined1  [8])0x0;
          pcStack_118 = (code *)0x0;
          apcStack_150[0] = pcVar19;
          plVar9 = *(longlong **)(lVar10 + 0x138);
          if (plVar9 != (longlong *)0x0) {
            *plVar9 = *plVar9 + 1;
          }
          pcVar12 = DAT_23ed6a4f8;
          if (pcVar19 == (code *)0x0) {
            if (iVar6 == 0) {
              iVar6 = (int)plVar1[5];
            }
            if (DAT_23ed6a4f8 == (code *)0x0) {
              pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              pcVar19 = apcStack_150[0];
            }
            else {
              pcVar19 = *(code **)DAT_23ed6a4f8;
              *(longlong *)DAT_23ed6a4f8 = 1;
              DAT_23ed6a4f8 = pcVar19;
              DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              pcVar19 = (code *)0x0;
            }
            pcVar18 = _PyRuntime_exref;
            *(longlong *)(pcVar12 + 0x10) = 0;
            *(longlong **)(pcVar12 + 0x18) = plVar1;
            *plVar1 = *plVar1 + 1;
            lVar14 = *(longlong *)(pcVar18 + 0x1f8);
            *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
            lVar14 = *(longlong *)(lVar14 + 0x10);
            *(int *)(pcVar12 + 0x24) = iVar6;
            lVar14 = *(longlong *)(lVar14 + 0x2e8);
            lVar20 = *(longlong *)(pcVar12 + -8);
            puVar2 = *(undefined8 **)(lVar14 + 8);
            *puVar2 = pcVar12 + -0x10;
            *(longlong *)(pcVar12 + -0x10) = lVar14;
            *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
            *(code **)(lVar14 + 8) = pcVar12 + -0x10;
            pcVar18 = pcVar12;
            if ((pcVar19 != (code *)0x0) &&
               (*(longlong *)pcVar19 = *(longlong *)pcVar19 + -1, *(longlong *)pcVar19 == 0)) {
              (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
            }
          }
          else {
            pcVar18 = apcStack_150[0];
            if (iVar6 != 0) {
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar18 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar18;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar18 = _PyRuntime_exref;
              *(longlong **)(pcVar12 + 0x18) = plVar1;
              *plVar1 = *plVar1 + 1;
              lVar14 = *(longlong *)(pcVar18 + 0x1f8);
              *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
              *(int *)(pcVar12 + 0x24) = iVar6;
              lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
              lVar20 = *(longlong *)(pcVar12 + -8);
              puVar2 = *(undefined8 **)(lVar14 + 8);
              *puVar2 = pcVar12 + -0x10;
              *(longlong *)(pcVar12 + -0x10) = lVar14;
              *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
              *(code **)(lVar14 + 8) = pcVar12 + -0x10;
              *(code **)(pcVar12 + 0x10) = pcVar19;
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
              pcVar18 = pcVar12;
              if ((apcStack_150[0] != (code *)0x0) &&
                 (*(longlong *)apcStack_150[0] = *(longlong *)apcStack_150[0] + -1,
                 *(longlong *)apcStack_150[0] == 0)) {
                (**(code **)(*(longlong *)(apcStack_150[0] + 8) + 0x30))();
              }
            }
          }
          apcStack_150[0] = pcVar18;
          pcVar19 = _Py_NoneStruct_exref;
          if (((code *)auStack_160._0_8_ != _Py_NoneStruct_exref) &&
             ((code *)auStack_160._0_8_ != (code *)0x0)) {
            FUN_23e91b1b0(lVar10,auStack_160,auStack_160 + 8,apcStack_150);
          }
          plVar7 = *(longlong **)(auStack_160._8_8_ + 0x28);
          if (apcStack_150[0] == pcVar19) {
            pcVar12 = (code *)0x0;
          }
          else {
            pcVar12 = apcStack_150[0];
            if (apcStack_150[0] != (code *)0x0) {
              *(longlong *)apcStack_150[0] = *(longlong *)apcStack_150[0] + 1;
            }
          }
          *(code **)(auStack_160._8_8_ + 0x28) = pcVar12;
          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
            (**(code **)(plVar7[1] + 0x30))();
          }
          plVar7 = *(longlong **)(lVar10 + 0x138);
          *(undefined8 *)(lVar10 + 0x138) = auStack_160._8_8_;
          if ((plVar7 != (longlong *)0x0) && (*plVar7 = *plVar7 + -1, *plVar7 == 0)) {
            (**(code **)(plVar7[1] + 0x30))();
          }
          *(longlong *)auStack_160._0_8_ = *(longlong *)auStack_160._0_8_ + -1;
          if (*(longlong *)auStack_160._0_8_ == 0) {
            (**(code **)(*(longlong *)(auStack_160._0_8_ + 8) + 0x30))();
          }
          if ((apcStack_150[0] != (code *)0x0) &&
             (*(longlong *)apcStack_150[0] = *(longlong *)apcStack_150[0] + -1,
             *(longlong *)apcStack_150[0] == 0)) {
            (**(code **)(*(longlong *)(apcStack_150[0] + 8) + 0x30))();
          }
          apcStack_150[0] = (code *)0x0;
          auStack_160 = (undefined1  [16])0x0;
          iVar6 = FUN_23a35ebd0(lVar10,*(undefined8 *)(*(longlong *)(lVar10 + 0x138) + 8),
                                *(undefined8 *)PyExc_Exception_exref);
          if (iVar6 == 0) {
            pcVar12 = *(code **)(lVar10 + 0x138);
            pcStack_118 = pcVar12;
            if ((pcVar12 == pcVar19) || (pcVar12 == (code *)0x0)) {
              pcVar19 = (code *)0x0;
              iVar6 = 0x123;
              auVar22 = *(undefined1 (*) [8])PyExc_RuntimeError_exref;
              pcVar18 = (code *)PyUnicode_FromString("No active exception to reraise");
              pcVar12 = *(code **)(lVar10 + 0x138);
              *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
              goto LAB_23e2c8965;
            }
            auVar22 = *(undefined1 (*) [8])(pcVar12 + 8);
            pcVar19 = *(code **)(pcVar12 + 0x28);
            *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
            *(longlong *)auVar22 = *(longlong *)auVar22 + 1;
            iVar6 = 0;
            pcVar18 = pcVar12;
            if (pcVar19 == (code *)0x0) {
              *(longlong **)(lVar10 + 0x138) = plVar9;
            }
            else {
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
              if (*(longlong **)(pcVar19 + 0x18) == plVar1) {
                *(undefined4 *)(plVar1 + 5) = *(undefined4 *)(pcVar19 + 0x24);
              }
              *(longlong **)(lVar10 + 0x138) = plVar9;
            }
LAB_23e2c7660:
            pcStack_110 = (code *)0x0;
            _auStack_120 = (undefined1  [16])0x0;
            *(longlong *)pcVar12 = *(longlong *)pcVar12 + -1;
            if (*(longlong *)pcVar12 == 0) {
              (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))();
            }
            pcStack_118 = pcVar18;
            auStack_120 = auVar22;
            if (pcVar19 == (code *)0x0) {
              pcStack_110 = (code *)0x0;
              if (iVar6 == 0) {
                iVar6 = (int)plVar1[5];
              }
LAB_23e2c89b6:
              pcVar19 = DAT_23ed6a4f8;
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar19 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                pcVar12 = pcStack_110;
              }
              else {
                pcVar12 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar12;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                pcVar12 = (code *)0x0;
              }
              pcVar18 = _PyRuntime_exref;
              *(longlong *)(pcVar19 + 0x10) = 0;
              *(longlong **)(pcVar19 + 0x18) = plVar1;
              *plVar1 = *plVar1 + 1;
              lVar14 = *(longlong *)(pcVar18 + 0x1f8);
              *(undefined4 *)(pcVar19 + 0x20) = 0xffffffff;
              lVar14 = *(longlong *)(lVar14 + 0x10);
              *(int *)(pcVar19 + 0x24) = iVar6;
              lVar14 = *(longlong *)(lVar14 + 0x2e8);
              lVar20 = *(longlong *)(pcVar19 + -8);
              puVar2 = *(undefined8 **)(lVar14 + 8);
              *puVar2 = pcVar19 + -0x10;
              *(longlong *)(pcVar19 + -0x10) = lVar14;
              *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
              *(code **)(lVar14 + 8) = pcVar19 + -0x10;
              if ((pcVar12 != (code *)0x0) &&
                 (*(longlong *)pcVar12 = *(longlong *)pcVar12 + -1, *(longlong *)pcVar12 == 0)) {
                (**(code **)(*(longlong *)(pcVar12 + 8) + 0x30))();
              }
              goto LAB_23e2c7759;
            }
LAB_23e2c769e:
            pcVar12 = DAT_23ed6a4f8;
            if (*(longlong **)(pcVar19 + 0x18) != plVar1) {
              if (iVar6 == 0) {
                iVar6 = (int)plVar1[5];
              }
              pcStack_110 = pcVar19;
              if (DAT_23ed6a4f8 == (code *)0x0) {
                pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
              }
              else {
                pcVar18 = *(code **)DAT_23ed6a4f8;
                *(longlong *)DAT_23ed6a4f8 = 1;
                DAT_23ed6a4f8 = pcVar18;
                DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
              }
              pcVar18 = _PyRuntime_exref;
              *(longlong **)(pcVar12 + 0x18) = plVar1;
              *plVar1 = *plVar1 + 1;
              lVar14 = *(longlong *)(pcVar18 + 0x1f8);
              *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
              *(int *)(pcVar12 + 0x24) = iVar6;
              lVar14 = *(longlong *)(*(longlong *)(lVar14 + 0x10) + 0x2e8);
              lVar20 = *(longlong *)(pcVar12 + -8);
              puVar2 = *(undefined8 **)(lVar14 + 8);
              *puVar2 = pcVar12 + -0x10;
              *(longlong *)(pcVar12 + -0x10) = lVar14;
              *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
              *(code **)(lVar14 + 8) = pcVar12 + -0x10;
              *(code **)(pcVar12 + 0x10) = pcVar19;
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
              pcVar19 = pcVar12;
              if ((pcStack_110 != (code *)0x0) &&
                 (*(longlong *)pcStack_110 = *(longlong *)pcStack_110 + -1,
                 *(longlong *)pcStack_110 == 0)) {
                (**(code **)(*(longlong *)(pcStack_110 + 8) + 0x30))();
              }
            }
LAB_23e2c7759:
            pcStack_110 = pcVar19;
            FUN_23e8bba40(plVar1,"ooooooooooooooo",plVar24,plVar13,plVar15,plStack_1e0,plStack_1b8,
                          plStack_198,plStack_1c0,plStack_1c8,plStack_1d0,plStack_1d8,plStack_1a8,
                          plStack_1b0,0,pplStack_190,plStack_1a0);
            if (_DAT_23eeb02d8 == plVar1) {
              *plVar1 = *plVar1 + -1;
              if (*plVar1 == 0) {
                (**(code **)(plVar1[1] + 0x30))(plVar1);
              }
              _DAT_23eeb02d8 = (longlong *)0x0;
            }
            lVar14 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
            plVar1 = *(longlong **)(lVar14 + 0x28);
            plVar7 = (longlong *)plVar1[2];
            *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
            *(undefined4 *)(plVar1 + 8) = 0xffffffff;
            if (plVar7 != (longlong *)0x0) {
              plVar1[2] = 0;
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                (**(code **)(plVar7[1] + 0x30))();
              }
            }
            *plVar1 = *plVar1 + -1;
            if (*plVar1 == 0) {
              (**(code **)(plVar1[1] + 0x30))(plVar1);
            }
            pcVar12 = pcStack_110;
            plVar1[0xf] = 0;
            auVar22 = auStack_120;
            pcVar19 = pcStack_118;
            _auStack_120 = (undefined1  [16])0x0;
            pcStack_110 = (code *)0x0;
            if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
              (**(code **)(plVar13[1] + 0x30))(plVar13);
            }
            if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            if ((plStack_1e0 != (longlong *)0x0) &&
               (lVar14 = *plStack_1e0, *plStack_1e0 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1e0[1] + 0x30))(plStack_1e0);
            }
            if ((plStack_1b8 != (longlong *)0x0) &&
               (lVar14 = *plStack_1b8, *plStack_1b8 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1b8[1] + 0x30))(plStack_1b8);
            }
            if ((plStack_198 != (longlong *)0x0) &&
               (lVar14 = *plStack_198, *plStack_198 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_198[1] + 0x30))(plStack_198);
            }
            if ((plStack_1c0 != (longlong *)0x0) &&
               (lVar14 = *plStack_1c0, *plStack_1c0 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1c0[1] + 0x30))(plStack_1c0);
            }
            if ((plStack_1c8 != (longlong *)0x0) &&
               (lVar14 = *plStack_1c8, *plStack_1c8 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1c8[1] + 0x30))(plStack_1c8);
            }
            if ((plStack_1d0 != (longlong *)0x0) &&
               (lVar14 = *plStack_1d0, *plStack_1d0 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1d0[1] + 0x30))(plStack_1d0);
            }
            if ((plStack_1d8 != (longlong *)0x0) &&
               (lVar14 = *plStack_1d8, *plStack_1d8 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1d8[1] + 0x30))(plStack_1d8);
            }
            if ((plStack_1a8 != (longlong *)0x0) &&
               (lVar14 = *plStack_1a8, *plStack_1a8 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1a8[1] + 0x30))(plStack_1a8);
            }
            if ((plStack_1b0 != (longlong *)0x0) &&
               (lVar14 = *plStack_1b0, *plStack_1b0 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1b0[1] + 0x30))(plStack_1b0);
            }
            if ((pplStack_190 != (longlong **)0x0) &&
               (lVar14 = (longlong)*pplStack_190, *pplStack_190 = (longlong *)(lVar14 + -1),
               lVar14 + -1 == 0)) {
              (**(code **)((longlong)pplStack_190[1] + 0x30))(pplStack_190);
            }
            if ((plStack_1a0 != (longlong *)0x0) &&
               (lVar14 = *plStack_1a0, *plStack_1a0 = lVar14 + -1, lVar14 + -1 == 0)) {
              (**(code **)(plStack_1a0[1] + 0x30))(plStack_1a0);
            }
            lVar14 = *plVar24;
            *plVar24 = lVar14 + -1;
            pcStack_110 = pcVar12;
            auStack_120 = auVar22;
            pcStack_118 = pcVar19;
            if (lVar14 + -1 == 0) {
              (**(code **)(plVar24[1] + 0x30))(plVar24);
            }
            FUN_23a33aa70(lVar10,auStack_120,pcStack_118,pcStack_110);
            return (code *)0x0;
          }
          plVar7 = *(longlong **)(lVar10 + 0x138);
          *plVar7 = *plVar7 + 1;
          lVar14 = FUN_23e8f6a70();
          if (lVar14 == 0) {
            FUN_23e915740(lVar10,auStack_120,DAT_23eeadcf8);
            auVar22 = auStack_120;
            pcVar19 = pcStack_110;
            pcVar18 = pcStack_118;
LAB_23e2c8920:
            pcStack_110 = (code *)0x0;
            _auStack_120 = (undefined1  [16])0x0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))(plVar7);
            }
            pcVar12 = *(code **)(lVar10 + 0x138);
            iVar6 = 0x175;
LAB_23e2c8965:
            *(longlong **)(lVar10 + 0x138) = plVar9;
            if (pcVar12 != (code *)0x0) goto LAB_23e2c7660;
            pcStack_118 = pcVar18;
            auStack_120 = auVar22;
            pcStack_110 = pcVar19;
            if (pcVar19 == (code *)0x0) goto LAB_23e2c89b6;
            goto LAB_23e2c769e;
          }
          plVar11 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eeade28);
          plVar8 = _DAT_23eeade58;
          if (plVar11 == (longlong *)0x0) {
            auVar22 = *(undefined1 (*) [8])(lVar10 + 0x60);
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            pcVar19 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            pcVar18 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c8920;
          }
          lVar14 = *(longlong *)(lVar10 + 0x10);
          plVar16 = *(longlong **)(lVar14 + 0xe20);
          if (plVar16 == (longlong *)0x0) {
            plVar16 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
          }
          else {
            lVar20 = plVar16[3];
            *(int *)(lVar14 + 0xebc) = *(int *)(lVar14 + 0xebc) + -1;
            *(longlong *)(lVar14 + 0xe20) = lVar20;
            *plVar16 = 1;
          }
          pcVar12 = _PyRuntime_exref;
          plVar16[4] = 0;
          lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
          lVar20 = plVar16[-1];
          puVar2 = *(undefined8 **)(lVar14 + 8);
          *puVar2 = plVar16 + -2;
          plVar16[-2] = lVar14;
          plVar16[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar14 + 8) = plVar16 + -2;
          plVar17 = DAT_23ed6a4c0;
          *plVar8 = *plVar8 + 1;
          plVar16[3] = (longlong)plVar8;
          pcVar12 = DAT_23ed6cd28;
          if (plVar17 != (longlong *)0x0) {
LAB_23e2c7141:
            pcStack_168 = pcVar12;
            plStack_170 = plVar7;
            lVar14 = FUN_23e94ed00(lVar10,plVar17,&plStack_170);
            if (lVar14 == 0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              *(undefined8 *)(lVar10 + 0x70) = 0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              *plVar11 = *plVar11 + -1;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
              }
              *plVar16 = *plVar16 + -1;
              auVar22 = auStack_120;
              pcVar19 = pcStack_110;
              pcVar18 = pcStack_118;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
                auVar22 = auStack_120;
                pcVar19 = pcStack_110;
                pcVar18 = pcStack_118;
              }
            }
            else {
              plVar16[4] = lVar14;
              lVar14 = PyUnicode_Join(DAT_23ed6cd28,plVar16);
              *plVar16 = *plVar16 + -1;
              if (*plVar16 == 0) {
                (**(code **)(plVar16[1] + 0x30))(plVar16);
              }
              if (lVar14 != 0) {
                lVar20 = *(longlong *)(lVar10 + 0x10);
                plVar8 = *(longlong **)(lVar20 + 0xe18);
                if (plVar8 == (longlong *)0x0) {
                  plVar8 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,1);
                }
                else {
                  lVar3 = plVar8[3];
                  *(int *)(lVar20 + 0xeb8) = *(int *)(lVar20 + 0xeb8) + -1;
                  *(longlong *)(lVar20 + 0xe18) = lVar3;
                  *plVar8 = 1;
                }
                lVar20 = *(longlong *)
                          (*(longlong *)(*(longlong *)(_PyRuntime_exref + 0x1f8) + 0x10) + 0x2e8);
                lVar3 = plVar8[-1];
                puVar2 = *(undefined8 **)(lVar20 + 8);
                *puVar2 = plVar8 + -2;
                plVar8[-2] = lVar20;
                plVar8[-1] = (ulonglong)((uint)lVar3 & 3) | (ulonglong)puVar2;
                *(longlong **)(lVar20 + 8) = plVar8 + -2;
                uVar23 = _DAT_23eeade60;
                plVar8[3] = lVar14;
                plVar16 = (longlong *)FUN_23e8d7870(lVar10,uVar23);
                *(undefined4 *)(plVar1 + 5) = 0x175;
                plVar17 = (longlong *)FUN_23a334c60(lVar10,plVar11,plVar8,plVar16);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  (**(code **)(plVar11[1] + 0x30))(plVar11);
                }
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  (**(code **)(plVar16[1] + 0x30))(plVar16);
                }
                if (plVar17 == (longlong *)0x0) {
                  auVar22 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcVar19 = *(code **)(lVar10 + 0x70);
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  pcVar18 = *(code **)(lVar10 + 0x68);
                  goto LAB_23e2c8920;
                }
                *plVar17 = *plVar17 + -1;
                if (*plVar17 == 0) {
                  (**(code **)(plVar17[1] + 0x30))(plVar17);
                }
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  (**(code **)(plVar7[1] + 0x30))(plVar7);
                }
                plVar1 = *(longlong **)(lVar10 + 0x138);
                *(longlong **)(lVar10 + 0x138) = plVar9;
                if ((plVar1 != (longlong *)0x0) && (*plVar1 = *plVar1 + -1, *plVar1 == 0)) {
                  (**(code **)(plVar1[1] + 0x30))();
                }
                goto LAB_23e2c730b;
              }
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              *plVar11 = *plVar11 + -1;
              auVar22 = auStack_120;
              pcVar19 = pcStack_110;
              pcVar18 = pcStack_118;
              if (*plVar11 == 0) {
                (**(code **)(plVar11[1] + 0x30))(plVar11);
                auVar22 = auStack_120;
                pcVar19 = pcStack_110;
                pcVar18 = pcStack_118;
              }
            }
            goto LAB_23e2c8920;
          }
          plVar17 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          plVar8 = plVar7;
          if (plVar17 != (longlong *)0x0) {
            *plVar17 = *plVar17 + 1;
            DAT_23ed6a4c0 = plVar17;
            goto LAB_23e2c7141;
          }
LAB_23e2c9560:
          do {
            PyErr_PrintEx(0);
            Py_Exit(1);
LAB_23e2c9573:
            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
          } while (plVar15 == (longlong *)0x0);
          *plVar15 = *plVar15 + 1;
          *plVar7 = (longlong)plVar15;
LAB_23e2c6b42:
          plStack_140 = plVar8;
          pcStack_138 = pcVar12;
          lVar14 = FUN_23e94ed00(lVar10,plVar15,&plStack_140);
          if (lVar14 == 0) {
            pcStack_110 = *(code **)(lVar10 + 0x70);
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c9379:
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
            if (*(longlong *)pcVar19 == 0) {
              (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
            }
LAB_23e2c9181:
            iVar6 = 0x127;
LAB_23e2c6e6f:
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          *(longlong *)(pcVar19 + 0x20) = lVar14;
          plVar7 = _DAT_23eeadd30;
          *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
          *(longlong **)(pcVar19 + 0x28) = plVar7;
          plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar19);
          *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
          if (*(longlong *)pcVar19 == 0) {
            (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
          }
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            *plVar13 = *plVar13 + -1;
            if (*plVar13 == 0) {
              (**(code **)(plVar13[1] + 0x30))();
            }
            goto LAB_23e2c9181;
          }
          *(undefined4 *)(plVar1 + 5) = 0x127;
          plVar15 = (longlong *)FUN_23e914090(lVar10,plVar13,plVar7);
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))();
          }
          if (plVar15 == (longlong *)0x0) {
LAB_23e2c9158:
            pcStack_110 = *(code **)(lVar10 + 0x70);
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2c9181;
          }
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb88);
          lVar14 = _DAT_23eeadd38;
          if (plVar13 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x128;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x128;
          plVar7 = (longlong *)
                   FUN_23e915840(lVar10,plVar13,_DAT_23eeada60,*(undefined8 *)(lVar14 + 0x18));
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x128;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb98);
          lVar14 = _DAT_23eeadd38;
          if (plVar13 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x129;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x129;
          plVar7 = (longlong *)
                   FUN_23e915840(lVar10,plVar13,_DAT_23eeada60,*(undefined8 *)(lVar14 + 0x18));
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x129;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadba8);
          lVar14 = _DAT_23eeadd38;
          if (plVar13 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x12a;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar13 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x12a;
          plVar7 = (longlong *)
                   FUN_23e915840(lVar10,plVar13,_DAT_23eeada60,*(undefined8 *)(lVar14 + 0x18));
          *plVar13 = *plVar13 + -1;
          if (*plVar13 == 0) {
            (**(code **)(plVar13[1] + 0x30))();
          }
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plVar13 = (longlong *)0x0;
            iVar6 = 0x12a;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            (**(code **)(plVar7[1] + 0x30))(plVar7);
          }
          plVar13 = (longlong *)0x0;
          lVar14 = *(longlong *)_Py_NoneStruct_exref;
LAB_23e2c6d58:
          pcVar19 = _Py_NoneStruct_exref;
          *(longlong *)_Py_NoneStruct_exref = lVar14 + 1;
          lVar14 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
          plVar1 = *(longlong **)(lVar14 + 0x28);
          plVar7 = (longlong *)plVar1[2];
          *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
          *(undefined4 *)(plVar1 + 8) = 0xffffffff;
          if (plVar7 != (longlong *)0x0) {
            plVar1[2] = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
          }
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          plVar1[0xf] = 0;
          if ((plVar13 == (longlong *)0x0) || (*plVar13 = *plVar13 + -1, *plVar13 != 0))
          goto LAB_23e2c6dfb;
          (**(code **)(plVar13[1] + 0x30))(plVar13);
          plStack_1a0 = (longlong *)0x0;
        }
        else {
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eead900);
          if (plVar15 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar13 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x12e;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          plVar13 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeadd40);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))();
          }
          if (plVar13 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x12e;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2c6ef9;
          }
          iVar6 = FUN_23a35f020();
          if (iVar6 == -1) {
            pcStack_110 = *(code **)(lVar10 + 0x70);
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            iVar6 = 0x12f;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c93d7:
            plStack_1a0 = (longlong *)0x0;
            plVar15 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          if (iVar6 == 0) {
            plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
            lVar14 = _DAT_23eeadd48;
            if (plVar7 == (longlong *)0x0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plStack_1a0 = (longlong *)0x0;
              iVar6 = 0x130;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              plStack_1e0 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              plVar15 = (longlong *)0x0;
              goto LAB_23e2c6ef9;
            }
            *(undefined4 *)(plVar1 + 5) = 0x130;
            plVar15 = (longlong *)
                      FUN_23e915840(lVar10,plVar7,_DAT_23eeada60,*(undefined8 *)(lVar14 + 0x18));
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
            if (plVar15 == (longlong *)0x0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plStack_1a0 = (longlong *)0x0;
              plVar15 = (longlong *)0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              iVar6 = 0x130;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              plStack_1e0 = (longlong *)0x0;
              goto LAB_23e2c6ef9;
            }
            lVar14 = *plVar15;
            *plVar15 = lVar14 + -1;
            if (lVar14 + -1 == 0) {
              (**(code **)(plVar15[1] + 0x30))(plVar15);
            }
            plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
            if (plVar7 == (longlong *)0x0) {
LAB_23e2c9699:
              pcStack_110 = *(code **)(lVar10 + 0x70);
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              *(undefined8 *)(lVar10 + 0x70) = 0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c96c2:
              iVar6 = 0x131;
              goto LAB_23e2c93d7;
            }
            plVar15 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eead9b8);
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
            plVar7 = _DAT_23eeadca8;
            if (plVar15 == (longlong *)0x0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plStack_1a0 = (longlong *)0x0;
              iVar6 = 0x131;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              plStack_1e0 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              plVar15 = (longlong *)0x0;
              goto LAB_23e2c6ef9;
            }
            lVar14 = *(longlong *)(lVar10 + 0x10);
            pcVar19 = *(code **)(lVar14 + 0xe28);
            if (pcVar19 == (code *)0x0) {
              pcVar19 = (code *)FUN_23e916a20(PyTuple_Type_exref,3);
            }
            else {
              lVar20 = *(longlong *)(pcVar19 + 0x18);
              *(int *)(lVar14 + 0xec0) = *(int *)(lVar14 + 0xec0) + -1;
              *(longlong *)(lVar14 + 0xe28) = lVar20;
              *(longlong *)pcVar19 = 1;
            }
            pcVar12 = _PyRuntime_exref;
            *(undefined1 (*) [16])(pcVar19 + 0x20) = (undefined1  [16])0x0;
            lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar12 + 0x1f8) + 0x10) + 0x2e8);
            lVar20 = *(longlong *)(pcVar19 + -8);
            puVar2 = *(undefined8 **)(lVar14 + 8);
            *puVar2 = pcVar19 + -0x10;
            *(longlong *)(pcVar19 + -0x10) = lVar14;
            *(ulonglong *)(pcVar19 + -8) = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
            *(code **)(lVar14 + 8) = pcVar19 + -0x10;
            *plVar7 = *plVar7 + 1;
            *(longlong **)(pcVar19 + 0x18) = plVar7;
            plVar8 = (longlong *)FUN_23e8f6920();
            pcVar12 = DAT_23ed6cd28;
            if (plVar8 == (longlong *)0x0) {
              FUN_23e915740(lVar10,auStack_120,DAT_23eeadd50);
LAB_23e2c9b9c:
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
              if (*(longlong *)pcVar19 == 0) {
                (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
              }
              goto LAB_23e2c96c2;
            }
            plVar7 = (longlong *)&DAT_23ed6a4c0;
            if (DAT_23ed6a4c0 == (longlong *)0x0) {
              plVar9 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
              if (plVar9 == (longlong *)0x0) goto LAB_23e2c9560;
              *plVar9 = *plVar9 + 1;
              DAT_23ed6a4c0 = plVar9;
            }
            pcStack_138 = pcVar12;
            plStack_140 = plVar8;
            lVar14 = FUN_23e94ed00(lVar10,DAT_23ed6a4c0,&plStack_140);
            if (lVar14 == 0) {
              pcStack_110 = *(code **)(lVar10 + 0x70);
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              *(undefined8 *)(lVar10 + 0x70) = 0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              goto LAB_23e2c9b9c;
            }
            *(longlong *)(pcVar19 + 0x20) = lVar14;
            plVar7 = _DAT_23eeadd30;
            *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
            *(longlong **)(pcVar19 + 0x28) = plVar7;
            plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,pcVar19);
            *(longlong *)pcVar19 = *(longlong *)pcVar19 + -1;
            if (*(longlong *)pcVar19 == 0) {
              (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))();
            }
            if (plVar7 == (longlong *)0x0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              *(undefined8 *)(lVar10 + 0x70) = 0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                FUN_23a334bc0();
              }
              goto LAB_23e2c96c2;
            }
            *(undefined4 *)(plVar1 + 5) = 0x131;
            plVar8 = (longlong *)FUN_23e914090(lVar10,plVar15,plVar7);
            *plVar15 = *plVar15 + -1;
            if (*plVar15 == 0) {
              (**(code **)(plVar15[1] + 0x30))();
            }
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
            if (plVar8 == (longlong *)0x0) goto LAB_23e2c9699;
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              (**(code **)(plVar8[1] + 0x30))(plVar8);
            }
            lVar14 = *(longlong *)_Py_NoneStruct_exref;
            goto LAB_23e2c6d58;
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eead900);
          if (plVar15 == (longlong *)0x0) {
            pcStack_110 = *(code **)(lVar10 + 0x70);
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2c9491:
            iVar6 = 0x135;
            goto LAB_23e2c93d7;
          }
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeadd58);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))();
          }
          if (plVar8 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            iVar6 = 0x135;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          iVar6 = FUN_23a35f020();
          lVar14 = *plVar8 + -1;
          if (iVar6 == -1) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            *plVar8 = lVar14;
            if (lVar14 == 0) {
              (**(code **)(plVar8[1] + 0x30))();
            }
            goto LAB_23e2c9491;
          }
          *plVar8 = lVar14;
          if (lVar14 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          if (iVar6 == 0) {
            plVar15 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
            if (plVar15 == (longlong *)0x0) {
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plStack_1a0 = (longlong *)0x0;
              iVar6 = 0x139;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              plStack_1e0 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              plVar15 = (longlong *)0x0;
            }
            else {
              *(undefined4 *)(plVar1 + 5) = 0x139;
              plVar8 = (longlong *)FUN_23e915840(lVar10,plVar15,_DAT_23eeada60);
              *plVar15 = *plVar15 + -1;
              if (*plVar15 == 0) {
                (**(code **)(plVar15[1] + 0x30))();
              }
              if (plVar8 != (longlong *)0x0) {
                lVar14 = *plVar8;
                *plVar8 = lVar14 + -1;
                if (lVar14 + -1 == 0) {
                  (**(code **)(plVar8[1] + 0x30))(plVar8);
                }
                plVar15 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
                if (plVar15 == (longlong *)0x0) {
LAB_23e2c9901:
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eead9b8);
                  *plVar15 = *plVar15 + -1;
                  if (*plVar15 == 0) {
                    (**(code **)(plVar15[1] + 0x30))();
                  }
                  plVar15 = _DAT_23eeadca8;
                  if (plVar9 == (longlong *)0x0) {
                    auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                    pcStack_118 = *(code **)(lVar10 + 0x68);
                    pcStack_110 = *(code **)(lVar10 + 0x70);
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    plStack_1a0 = (longlong *)0x0;
                    pplStack_190 = (longlong **)0x0;
                    plStack_1b0 = (longlong *)0x0;
                    plStack_1a8 = (longlong *)0x0;
                    plStack_1d8 = (longlong *)0x0;
                    plStack_1d0 = (longlong *)0x0;
                    plStack_1c8 = (longlong *)0x0;
                    plStack_1c0 = (longlong *)0x0;
                    plStack_198 = (longlong *)0x0;
                    plStack_1b8 = (longlong *)0x0;
                    plStack_1e0 = (longlong *)0x0;
                    iVar6 = 0x13a;
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plVar15 = (longlong *)0x0;
                    goto LAB_23e2c6ef9;
                  }
                  lVar14 = *(longlong *)(lVar10 + 0x10);
                  plVar11 = *(longlong **)(lVar14 + 0xe28);
                  if (plVar11 == (longlong *)0x0) {
                    plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
                  }
                  else {
                    lVar20 = plVar11[3];
                    *(int *)(lVar14 + 0xec0) = *(int *)(lVar14 + 0xec0) + -1;
                    *(longlong *)(lVar14 + 0xe28) = lVar20;
                    *plVar11 = 1;
                  }
                  pcVar19 = _PyRuntime_exref;
                  *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
                  lVar14 = *(longlong *)
                            (*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
                  lVar20 = plVar11[-1];
                  puVar2 = *(undefined8 **)(lVar14 + 8);
                  *puVar2 = plVar11 + -2;
                  plVar11[-2] = lVar14;
                  plVar11[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
                  *(longlong **)(lVar14 + 8) = plVar11 + -2;
                  *plVar15 = *plVar15 + 1;
                  plVar11[3] = (longlong)plVar15;
                  plVar8 = (longlong *)FUN_23e8f6530();
                  pcVar12 = DAT_23ed6cd28;
                  if (plVar8 == (longlong *)0x0) {
                    FUN_23e915740(lVar10,auStack_120,DAT_23eeadd28);
                  }
                  else {
                    pcVar19 = (code *)&DAT_23ed6a4c0;
                    if (DAT_23ed6a4c0 == (longlong *)0x0) {
                      plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                      if (plVar15 == (longlong *)0x0) goto LAB_23e2c9560;
                      *plVar15 = *plVar15 + 1;
                      DAT_23ed6a4c0 = plVar15;
                    }
                    pcStack_138 = pcVar12;
                    plStack_140 = plVar8;
                    lVar14 = FUN_23e94ed00(lVar10,DAT_23ed6a4c0,&plStack_140);
                    if (lVar14 != 0) {
                      plVar11[4] = lVar14;
                      pcVar19 = PyUnicode_Join_exref;
                      plVar7 = _DAT_23eeadd30;
                      *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
                      plVar11[5] = (longlong)plVar7;
                      plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar7 != (longlong *)0x0) {
                        *(undefined4 *)(plVar1 + 5) = 0x13a;
                        plVar15 = (longlong *)FUN_23e914090(lVar10,plVar9,plVar7);
                        *plVar9 = *plVar9 + -1;
                        if (*plVar9 == 0) {
                          FUN_23a334bc0();
                        }
                        *plVar7 = *plVar7 + -1;
                        if (*plVar7 == 0) {
                          FUN_23a334bc0();
                        }
                        if (plVar15 != (longlong *)0x0) goto LAB_23e2c7eeb;
                        goto LAB_23e2c9901;
                      }
                      auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                      pcStack_118 = *(code **)(lVar10 + 0x68);
                      pcStack_110 = *(code **)(lVar10 + 0x70);
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0();
                      }
                      goto LAB_23e2c992a;
                    }
                    pcStack_110 = *(code **)(lVar10 + 0x70);
                    auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                    pcStack_118 = *(code **)(lVar10 + 0x68);
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  }
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    FUN_23a334bc0();
                  }
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0();
                  }
                }
LAB_23e2c992a:
                iVar6 = 0x13a;
                goto LAB_23e2c93d7;
              }
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              pcStack_110 = *(code **)(lVar10 + 0x70);
              plVar15 = (longlong *)0x0;
              *(undefined8 *)(lVar10 + 0x70) = 0;
              iVar6 = 0x139;
              plStack_1a0 = (longlong *)0x0;
              pplStack_190 = (longlong **)0x0;
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              plStack_1e0 = (longlong *)0x0;
            }
            goto LAB_23e2c6ef9;
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
          if (plVar15 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plStack_1a0 = (longlong *)0x0;
            iVar6 = 0x136;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x136;
          plVar8 = (longlong *)FUN_23e915840(lVar10,plVar15,_DAT_23eeada60);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))();
          }
          if (plVar8 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plVar15 = (longlong *)0x0;
            iVar6 = 0x136;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1e0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          lVar14 = *plVar8;
          *plVar8 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            (**(code **)(plVar8[1] + 0x30))(plVar8);
          }
          plVar15 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb78);
          if (plVar15 == (longlong *)0x0) {
LAB_23e2ca038:
            pcStack_110 = *(code **)(lVar10 + 0x70);
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ca061:
            iVar6 = 0x137;
            goto LAB_23e2c93d7;
          }
          plVar9 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eead9b8);
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            (**(code **)(plVar15[1] + 0x30))();
          }
          plVar15 = _DAT_23eeadca8;
          if (plVar9 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x137;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plVar15 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          lVar14 = *(longlong *)(lVar10 + 0x10);
          plVar11 = *(longlong **)(lVar14 + 0xe28);
          if (plVar11 == (longlong *)0x0) {
            plVar11 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,3);
          }
          else {
            lVar20 = plVar11[3];
            *(int *)(lVar14 + 0xec0) = *(int *)(lVar14 + 0xec0) + -1;
            *(longlong *)(lVar14 + 0xe28) = lVar20;
            *plVar11 = 1;
          }
          pcVar19 = _PyRuntime_exref;
          *(undefined1 (*) [16])(plVar11 + 4) = (undefined1  [16])0x0;
          lVar14 = *(longlong *)(*(longlong *)(*(longlong *)(pcVar19 + 0x1f8) + 0x10) + 0x2e8);
          lVar20 = plVar11[-1];
          puVar2 = *(undefined8 **)(lVar14 + 8);
          *puVar2 = plVar11 + -2;
          plVar11[-2] = lVar14;
          plVar11[-1] = (ulonglong)((uint)lVar20 & 3) | (ulonglong)puVar2;
          *(longlong **)(lVar14 + 8) = plVar11 + -2;
          *plVar15 = *plVar15 + 1;
          plVar11[3] = (longlong)plVar15;
          plVar8 = (longlong *)FUN_23e8f6680();
          pcVar12 = DAT_23ed6cd28;
          if (plVar8 == (longlong *)0x0) {
            FUN_23e915740(lVar10,auStack_120,DAT_23eeadd68);
LAB_23e2ca437:
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              FUN_23a334bc0();
            }
            *plVar11 = *plVar11 + -1;
            if (*plVar11 == 0) {
              FUN_23a334bc0();
            }
            goto LAB_23e2ca061;
          }
          pcVar19 = (code *)&DAT_23ed6a4c0;
          if (DAT_23ed6a4c0 == (longlong *)0x0) {
            plVar15 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
            if (plVar15 == (longlong *)0x0) goto LAB_23e2c9560;
            *plVar15 = *plVar15 + 1;
            DAT_23ed6a4c0 = plVar15;
          }
          pcStack_138 = pcVar12;
          plStack_140 = plVar8;
          lVar14 = FUN_23e94ed00(lVar10,DAT_23ed6a4c0,&plStack_140);
          if (lVar14 == 0) {
            pcStack_110 = *(code **)(lVar10 + 0x70);
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2ca437;
          }
          plVar11[4] = lVar14;
          pcVar19 = PyUnicode_Join_exref;
          plVar7 = _DAT_23eeadd30;
          *_DAT_23eeadd30 = *_DAT_23eeadd30 + 1;
          plVar11[5] = (longlong)plVar7;
          plVar7 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar11);
          *plVar11 = *plVar11 + -1;
          if (*plVar11 == 0) {
            FUN_23a334bc0();
          }
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            *plVar9 = *plVar9 + -1;
            if (*plVar9 == 0) {
              FUN_23a334bc0();
            }
            goto LAB_23e2ca061;
          }
          *(undefined4 *)(plVar1 + 5) = 0x137;
          plVar15 = (longlong *)FUN_23e914090(lVar10,plVar9,plVar7);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            FUN_23a334bc0();
          }
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0();
          }
          if (plVar15 == (longlong *)0x0) goto LAB_23e2ca038;
LAB_23e2c7eeb:
          pplStack_190 = &plStack_140;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            FUN_23a334bc0(plVar15);
          }
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar13,DAT_23ed6ce40);
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            plVar15 = (longlong *)0x0;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x13d;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1e0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x13d;
          plVar15 = (longlong *)FUN_23e9557e0(lVar10,plVar7);
          lVar14 = *plVar7;
          *plVar7 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            FUN_23a334bc0();
          }
          if (plVar15 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x13d;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2c6ef9;
          }
          iVar6 = FUN_23a35f020();
          if (iVar6 == -1) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            iVar6 = 0x13e;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            goto LAB_23e2c6ef9;
          }
          if (iVar6 != 0) {
            plVar7 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeadd80);
            if (plVar7 == (longlong *)0x0) {
LAB_23e2ca965:
              pcStack_110 = *(code **)(lVar10 + 0x70);
              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
              pcStack_118 = *(code **)(lVar10 + 0x68);
              *(undefined8 *)(lVar10 + 0x70) = 0;
              *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2ca98c:
              uVar23 = 0x141;
LAB_23e2ca991:
              plStack_1b0 = (longlong *)0x0;
              plStack_1a8 = (longlong *)0x0;
              plStack_1d8 = (longlong *)0x0;
              plStack_1d0 = (longlong *)0x0;
              plStack_1c8 = (longlong *)0x0;
              plStack_1c0 = (longlong *)0x0;
              plStack_198 = (longlong *)0x0;
              plStack_1b8 = (longlong *)0x0;
              plStack_1e0 = (longlong *)0x0;
            }
            else {
              *(undefined4 *)(plVar1 + 5) = 0x141;
              plVar8 = (longlong *)FUN_23e94bb80(lVar10,plVar7);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                FUN_23a334bc0();
              }
              if (plVar8 == (longlong *)0x0) goto LAB_23e2ca965;
              iVar6 = FUN_23a35f020();
              lVar14 = *plVar8 + -1;
              if (iVar6 == -1) {
                auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                pcStack_118 = *(code **)(lVar10 + 0x68);
                pcStack_110 = *(code **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar8 = lVar14;
                if (lVar14 == 0) {
                  FUN_23a334bc0();
                }
                goto LAB_23e2ca98c;
              }
              *plVar8 = lVar14;
              if (lVar14 == 0) {
                FUN_23a334bc0(plVar8);
              }
              if (iVar6 != 0) {
                lVar14 = FUN_23e8f67d0();
                if (lVar14 == 0) {
                  FUN_23e915740(lVar10,auStack_120);
                }
                else {
                  plVar7 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eeadd98);
                  if (plVar7 == (longlong *)0x0) {
                    auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                    pcStack_118 = *(code **)(lVar10 + 0x68);
                    pcStack_110 = *(code **)(lVar10 + 0x70);
                    uVar23 = 0x142;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    plStack_1b0 = (longlong *)0x0;
                    plStack_1a8 = (longlong *)0x0;
                    plStack_1d8 = (longlong *)0x0;
                    plStack_1d0 = (longlong *)0x0;
                    plStack_1c8 = (longlong *)0x0;
                    plStack_1c0 = (longlong *)0x0;
                    plStack_198 = (longlong *)0x0;
                    plStack_1e0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    plStack_1b8 = (longlong *)0x0;
                    goto LAB_23e2ca9dc;
                  }
                  plVar8 = (longlong *)FUN_23e8bc2f0(plVar15,_DAT_23eeadda0);
                  if (plVar8 != (longlong *)0x0) {
                    *(undefined4 *)(plVar1 + 5) = 0x142;
                    plVar9 = (longlong *)FUN_23e9557e0(lVar10,plVar8);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar9 != (longlong *)0x0) {
                      *(undefined4 *)(plVar1 + 5) = 0x142;
                      plStack_1e0 = (longlong *)FUN_23e914090(lVar10,plVar7);
                      lVar14 = *plVar7;
                      *plVar7 = lVar14 + -1;
                      if (lVar14 + -1 == 0) {
                        FUN_23a334bc0();
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plStack_1e0 != (longlong *)0x0) goto LAB_23e2c80d9;
                      auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                      pcStack_118 = *(code **)(lVar10 + 0x68);
                      pcStack_110 = *(code **)(lVar10 + 0x70);
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      goto LAB_23e2cb455;
                    }
                  }
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  lVar14 = *plVar7;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  *plVar7 = lVar14 + -1;
                  if (lVar14 + -1 == 0) {
                    FUN_23a334bc0();
                  }
                }
LAB_23e2cb455:
                uVar23 = 0x142;
                goto LAB_23e2ca991;
              }
              lVar14 = FUN_23e8f67d0();
              if (lVar14 == 0) {
                FUN_23e915740(lVar10,auStack_120,DAT_23eeadd90);
                plStack_1e0 = (longlong *)0x0;
LAB_23e2cb4ca:
                uVar23 = 0x144;
                plStack_1b0 = (longlong *)0x0;
                plStack_1a8 = (longlong *)0x0;
                plStack_1d8 = (longlong *)0x0;
                plStack_1d0 = (longlong *)0x0;
                plStack_1c8 = (longlong *)0x0;
                plStack_1c0 = (longlong *)0x0;
                plStack_198 = (longlong *)0x0;
                plStack_1b8 = (longlong *)0x0;
              }
              else {
                *(undefined4 *)(plVar1 + 5) = 0x144;
                plStack_1e0 = (longlong *)FUN_23e915840(lVar10,lVar14,_DAT_23eeadd98);
                if (plStack_1e0 == (longlong *)0x0) {
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2cb4ca;
                }
LAB_23e2c80d9:
                *(undefined4 *)(plVar1 + 5) = 0x147;
                plStack_1b8 = (longlong *)FUN_23e91bfe0(lVar10,plStack_1e0,_DAT_23eeaddb0);
                lVar14 = _DAT_23eeaddc0;
                if (plStack_1b8 == (longlong *)0x0) {
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  uVar23 = 0x147;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  plStack_1b0 = (longlong *)0x0;
                  plStack_1a8 = (longlong *)0x0;
                  plStack_1d8 = (longlong *)0x0;
                  plStack_1d0 = (longlong *)0x0;
                  plStack_1c8 = (longlong *)0x0;
                  plStack_1c0 = (longlong *)0x0;
                  plStack_198 = (longlong *)0x0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  *(undefined4 *)(plVar1 + 5) = 0x14a;
                  plStack_198 = (longlong *)
                                FUN_23e915840(lVar10,plStack_1b8,_DAT_23eeaddb8,
                                              *(undefined8 *)(lVar14 + 0x18));
                  if (plStack_198 == (longlong *)0x0) {
                    auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                    pcStack_118 = *(code **)(lVar10 + 0x68);
                    pcStack_110 = *(code **)(lVar10 + 0x70);
                    uVar23 = 0x14a;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    plStack_1b0 = (longlong *)0x0;
                    plStack_1a8 = (longlong *)0x0;
                    plStack_1d8 = (longlong *)0x0;
                    plStack_1d0 = (longlong *)0x0;
                    plStack_1c8 = (longlong *)0x0;
                    plStack_1c0 = (longlong *)0x0;
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  }
                  else {
                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb88);
                    if (plVar7 == (longlong *)0x0) {
                      auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                      pcStack_118 = *(code **)(lVar10 + 0x68);
                      pcStack_110 = *(code **)(lVar10 + 0x70);
                      uVar23 = 0x14c;
                      *(undefined8 *)(lVar10 + 0x70) = 0;
                      plStack_1b0 = (longlong *)0x0;
                      plStack_1a8 = (longlong *)0x0;
                      plStack_1d8 = (longlong *)0x0;
                      plStack_1d0 = (longlong *)0x0;
                      plStack_1c0 = (longlong *)0x0;
                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                      plStack_1c8 = (longlong *)0x0;
                    }
                    else {
                      *(undefined4 *)(plVar1 + 5) = 0x14c;
                      plVar8 = (longlong *)FUN_23e915840(lVar10,plVar7,_DAT_23eeada60);
                      lVar14 = *plVar7;
                      *plVar7 = lVar14 + -1;
                      if (lVar14 + -1 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar8 == (longlong *)0x0) {
                        auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                        pcStack_118 = *(code **)(lVar10 + 0x68);
                        pcStack_110 = *(code **)(lVar10 + 0x70);
                        *(undefined8 *)(lVar10 + 0x70) = 0;
                        plStack_1b0 = (longlong *)0x0;
                        plStack_1a8 = (longlong *)0x0;
                        plStack_1d8 = (longlong *)0x0;
                        plStack_1d0 = (longlong *)0x0;
                        plStack_1c8 = (longlong *)0x0;
                        uVar23 = 0x14c;
                        *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                        plStack_1c0 = (longlong *)0x0;
                      }
                      else {
                        lVar14 = *plVar8;
                        *plVar8 = lVar14 + -1;
                        if (lVar14 + -1 == 0) {
                          FUN_23a334bc0(plVar8);
                        }
                        lVar14 = FUN_23e8f67d0();
                        if (lVar14 == 0) {
                          FUN_23e915740(lVar10,auStack_120,DAT_23eeadd90);
                        }
                        else {
                          plVar7 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eeaddc8);
                          if (plVar7 == (longlong *)0x0) {
                            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                            pcStack_118 = *(code **)(lVar10 + 0x68);
                            pcStack_110 = *(code **)(lVar10 + 0x70);
                            uVar23 = 0x14f;
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            plStack_1b0 = (longlong *)0x0;
                            plStack_1a8 = (longlong *)0x0;
                            plStack_1d8 = (longlong *)0x0;
                            plStack_1d0 = (longlong *)0x0;
                            plStack_1c0 = (longlong *)0x0;
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                            plStack_1c8 = (longlong *)0x0;
                            goto LAB_23e2ca9dc;
                          }
                          lVar14 = *(longlong *)(DAT_23eeae258 + 0x20);
                          if (*(char *)(lVar14 + 10) == '\0') {
                            plVar8 = (longlong *)FUN_23a37a020(DAT_23eeae258,DAT_23eeaddd0);
                            if (plVar8 == (longlong *)0x0) goto LAB_23e2cc3cb;
                            lVar20 = *plVar8;
LAB_23e2cc3c2:
                            if (lVar20 == 0) goto LAB_23e2cc3cb;
LAB_23e2c82a2:
                            plVar8 = (longlong *)FUN_23e8bc2f0(lVar20,_DAT_23eeaddd8);
                            if (plVar8 != (longlong *)0x0) {
                              *(undefined4 *)(plVar1 + 5) = 0x14f;
                              plStack_1c0 = (longlong *)FUN_23e914090(lVar10,plVar7,plVar8);
                              lVar14 = *plVar7;
                              *plVar7 = lVar14 + -1;
                              if (lVar14 + -1 == 0) {
                                FUN_23a334bc0();
                              }
                              *plVar8 = *plVar8 + -1;
                              if (*plVar8 == 0) {
                                FUN_23a334bc0();
                              }
                              if (plStack_1c0 == (longlong *)0x0) {
                                pcStack_110 = *(code **)(lVar10 + 0x70);
                                auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                pcStack_118 = *(code **)(lVar10 + 0x68);
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                goto LAB_23e2cc30e;
                              }
                              plStack_1c8 = (longlong *)FUN_23e8c6640(plStack_1e0,plStack_1c0);
                              if (plStack_1c8 == (longlong *)0x0) {
                                auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                pcStack_118 = *(code **)(lVar10 + 0x68);
                                pcStack_110 = *(code **)(lVar10 + 0x70);
                                uVar23 = 0x150;
                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                plStack_1b0 = (longlong *)0x0;
                                plStack_1a8 = (longlong *)0x0;
                                plStack_1d8 = (longlong *)0x0;
                                plStack_1d0 = (longlong *)0x0;
                                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                              }
                              else {
                                *(undefined4 *)(plVar1 + 5) = 0x152;
                                plVar7 = (longlong *)FUN_23e91bfe0(lVar10,plStack_1c8);
                                if (plVar7 == (longlong *)0x0) {
                                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                  pcStack_118 = *(code **)(lVar10 + 0x68);
                                  pcStack_110 = *(code **)(lVar10 + 0x70);
                                  uVar23 = 0x152;
                                  *(undefined8 *)(lVar10 + 0x70) = 0;
                                  plStack_1b0 = (longlong *)0x0;
                                  plStack_1a8 = (longlong *)0x0;
                                  plStack_1d8 = (longlong *)0x0;
                                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                  plStack_1d0 = (longlong *)0x0;
                                }
                                else {
                                  iVar6 = FUN_23e97de20(plVar7,DAT_23ed6ccf0);
                                  lVar14 = *plVar7;
                                  *plVar7 = lVar14 + -1;
                                  if (lVar14 + -1 == 0) {
                                    FUN_23a334bc0();
                                  }
                                  if (iVar6 == -1) {
                                    auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                    pcStack_118 = *(code **)(lVar10 + 0x68);
                                    pcStack_110 = *(code **)(lVar10 + 0x70);
                                    *(undefined8 *)(lVar10 + 0x70) = 0;
                                    uVar23 = 0x152;
                                    plStack_1b0 = (longlong *)0x0;
                                    plStack_1a8 = (longlong *)0x0;
                                    plStack_1d8 = (longlong *)0x0;
                                    plStack_1d0 = (longlong *)0x0;
                                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                  }
                                  else if (iVar6 == 1) {
                                    plStack_1d0 = (longlong *)
                                                  FUN_23e8bc2f0(plStack_1c8,_DAT_23eeadde8);
                                    if (plStack_1d0 == (longlong *)0x0) {
                                      auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                      pcStack_118 = *(code **)(lVar10 + 0x68);
                                      pcStack_110 = *(code **)(lVar10 + 0x70);
                                      uVar23 = 0x153;
                                      *(undefined8 *)(lVar10 + 0x70) = 0;
                                      plStack_1b0 = (longlong *)0x0;
                                      plStack_1a8 = (longlong *)0x0;
                                      plStack_1d8 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                    }
                                    else {
                                      plVar7 = (longlong *)FUN_23e8bc2f0(plStack_1c8,_DAT_23eeaddf0)
                                      ;
                                      if (plVar7 == (longlong *)0x0) {
                                        auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                        pcStack_118 = *(code **)(lVar10 + 0x68);
                                        pcStack_110 = *(code **)(lVar10 + 0x70);
                                        uVar23 = 0x154;
                                        *(undefined8 *)(lVar10 + 0x70) = 0;
                                        plStack_1b0 = (longlong *)0x0;
                                        plStack_1d8 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(lVar10 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plStack_1a8 = (longlong *)0x0;
                                      }
                                      else {
                                        plStack_1d8 = (longlong *)
                                                      FUN_23e8c1ce0(plVar7,_DAT_23eeaddf8);
                                        lVar14 = *plVar7;
                                        *plVar7 = lVar14 + -1;
                                        if (lVar14 + -1 == 0) {
                                          FUN_23a334bc0();
                                        }
                                        if (plStack_1d8 == (longlong *)0x0) {
                                          auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                          pcStack_118 = *(code **)(lVar10 + 0x68);
                                          pcStack_110 = *(code **)(lVar10 + 0x70);
                                          uVar23 = 0x154;
                                          *(undefined8 *)(lVar10 + 0x70) = 0;
                                          plStack_1b0 = (longlong *)0x0;
                                          plStack_1a8 = (longlong *)0x0;
                                          *(undefined1 (*) [16])(lVar10 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          plVar7 = (longlong *)FUN_23e8bc2f0();
                                          if (plVar7 == (longlong *)0x0) {
LAB_23e2cc0e7:
                                            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                            pcStack_118 = *(code **)(lVar10 + 0x68);
                                            pcStack_110 = *(code **)(lVar10 + 0x70);
                                            *(undefined8 *)(lVar10 + 0x70) = 0;
                                            uVar23 = 0x155;
                                            plStack_1b0 = (longlong *)0x0;
                                            plStack_1a8 = (longlong *)0x0;
                                            *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                 (undefined1  [16])0x0;
                                          }
                                          else {
                                            plVar8 = (longlong *)
                                                     FUN_23e8c2690(plVar7,_DAT_23eeaddf8);
                                            *plVar7 = *plVar7 + -1;
                                            if (*plVar7 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plVar8 == (longlong *)0x0) {
                                              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                              pcStack_118 = *(code **)(lVar10 + 0x68);
                                              pcStack_110 = *(code **)(lVar10 + 0x70);
                                              uVar23 = 0x155;
                                              *(undefined8 *)(lVar10 + 0x70) = 0;
                                              plStack_1a8 = (longlong *)0x0;
                                              *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              plStack_1b0 = (longlong *)0x0;
                                            }
                                            else {
                                              plStack_1a8 = (longlong *)FUN_23e8c1ce0();
                                              lVar14 = *plVar8;
                                              *plVar8 = lVar14 + -1;
                                              if (lVar14 + -1 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              if (plStack_1a8 == (longlong *)0x0)
                                              goto LAB_23e2cc0e7;
                                              iVar6 = FUN_23e97de20(plStack_1d0,DAT_23ed6ccf0);
                                              if (iVar6 == -1) {
                                                pcStack_110 = *(code **)(lVar10 + 0x70);
                                                auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                                pcStack_118 = *(code **)(lVar10 + 0x68);
                                                uVar23 = 0x157;
                                                *(undefined8 *)(lVar10 + 0x70) = 0;
                                                plStack_1b0 = (longlong *)0x0;
                                                *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                     (undefined1  [16])0x0;
                                              }
                                              else if (iVar6 == 1) {
                                                lVar14 = FUN_23e94f9d0(lVar10,plStack_1d0,
                                                                       DAT_23ed6cd28);
                                                if (lVar14 == 0) {
LAB_23e2cc000:
                                                  pcStack_110 = *(code **)(lVar10 + 0x70);
                                                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60)
                                                  ;
                                                  pcStack_118 = *(code **)(lVar10 + 0x68);
                                                  *(undefined8 *)(lVar10 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else {
                                                  plVar8 = (longlong *)
                                                           FUN_23e916ad0(*(undefined8 *)
                                                                          (lVar10 + 0x10),6);
                                                  plVar8[3] = lVar14;
                                                  plVar7 = _DAT_23eeade08;
                                                  *_DAT_23eeade08 = *_DAT_23eeade08 + 1;
                                                  plVar8[4] = (longlong)plVar7;
                                                  lVar14 = FUN_23e94f9d0(lVar10,plStack_1d8,
                                                                         DAT_23ed6cd28);
                                                  if (lVar14 != 0) {
                                                    plVar8[5] = lVar14;
                                                    plVar7 = _DAT_23eeade10;
                                                    *_DAT_23eeade10 = *_DAT_23eeade10 + 1;
                                                    plVar8[6] = (longlong)plVar7;
                                                    lVar14 = FUN_23e94f9d0(lVar10,plStack_1a8,
                                                                           DAT_23ed6cd28);
                                                    if (lVar14 != 0) {
                                                      plVar8[7] = lVar14;
                                                      plVar7 = _DAT_23eeade18;
                                                      *_DAT_23eeade18 = *_DAT_23eeade18 + 1;
                                                      plVar8[8] = (longlong)plVar7;
                                                      plStack_1b0 = (longlong *)
                                                                    (*pcVar19)(DAT_23ed6cd28,plVar8)
                                                      ;
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plStack_1b0 != (longlong *)0x0)
                                                      goto LAB_23e2cbae8;
                                                      goto LAB_23e2cc000;
                                                    }
                                                  }
                                                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60)
                                                  ;
                                                  pcStack_118 = *(code **)(lVar10 + 0x68);
                                                  pcStack_110 = *(code **)(lVar10 + 0x70);
                                                  *(undefined8 *)(lVar10 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  *plVar8 = *plVar8 + -1;
                                                  if (*plVar8 == 0) {
                                                    FUN_23a334bc0();
                                                  }
                                                }
                                                uVar23 = 0x158;
                                                plStack_1b0 = (longlong *)0x0;
                                              }
                                              else {
                                                iVar6 = FUN_23e97de20(plStack_1d8,DAT_23ed6ccf0);
                                                if (iVar6 == -1) {
                                                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60)
                                                  ;
                                                  pcStack_118 = *(code **)(lVar10 + 0x68);
                                                  pcStack_110 = *(code **)(lVar10 + 0x70);
                                                  *(undefined8 *)(lVar10 + 0x70) = 0;
                                                  uVar23 = 0x159;
                                                  plStack_1b0 = (longlong *)0x0;
                                                  *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                                else if (iVar6 == 1) {
                                                  lVar14 = FUN_23e94f9d0(lVar10,plStack_1d8,
                                                                         DAT_23ed6cd28);
                                                  if (lVar14 == 0) {
LAB_23e2cbe79:
                                                    pcStack_110 = *(code **)(lVar10 + 0x70);
                                                    auStack_120 = *(undefined1 (*) [8])
                                                                   (lVar10 + 0x60);
                                                    pcStack_118 = *(code **)(lVar10 + 0x68);
                                                    *(undefined8 *)(lVar10 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar8 = (longlong *)
                                                             FUN_23e916ad0(*(undefined8 *)
                                                                            (lVar10 + 0x10),4);
                                                    plVar8[3] = lVar14;
                                                    plVar7 = _DAT_23eeade10;
                                                    *_DAT_23eeade10 = *_DAT_23eeade10 + 1;
                                                    plVar8[4] = (longlong)plVar7;
                                                    lVar14 = FUN_23e94f9d0(lVar10,plStack_1a8);
                                                    if (lVar14 != 0) {
                                                      plVar8[5] = lVar14;
                                                      plVar7 = _DAT_23eeade18;
                                                      *_DAT_23eeade18 = *_DAT_23eeade18 + 1;
                                                      plVar8[6] = (longlong)plVar7;
                                                      plStack_1b0 = (longlong *)
                                                                    (*pcVar19)(DAT_23ed6cd28,plVar8)
                                                      ;
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plStack_1b0 != (longlong *)0x0)
                                                      goto LAB_23e2cbae8;
                                                      goto LAB_23e2cbe79;
                                                    }
                                                    auStack_120 = *(undefined1 (*) [8])
                                                                   (lVar10 + 0x60);
                                                    pcStack_118 = *(code **)(lVar10 + 0x68);
                                                    pcStack_110 = *(code **)(lVar10 + 0x70);
                                                    *(undefined8 *)(lVar10 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0();
                                                      uVar23 = 0x15a;
                                                      plStack_1b0 = (longlong *)0x0;
                                                      goto LAB_23e2ca9dc;
                                                    }
                                                  }
                                                  uVar23 = 0x15a;
                                                  plStack_1b0 = (longlong *)0x0;
                                                }
                                                else {
                                                  plStack_1b0 = (longlong *)
                                                                FUN_23e94f9d0(lVar10,plStack_1a8,
                                                                              DAT_23ed6cd28);
                                                  if (plStack_1b0 != (longlong *)0x0) {
                                                    plVar8 = (longlong *)
                                                             FUN_23e916ad0(*(undefined8 *)
                                                                            (lVar10 + 0x10),2);
                                                    plVar8[3] = (longlong)plStack_1b0;
                                                    plVar7 = _DAT_23eeade18;
                                                    *_DAT_23eeade18 = *_DAT_23eeade18 + 1;
                                                    plVar8[4] = (longlong)plVar7;
                                                    plStack_1b0 = (longlong *)
                                                                  (*pcVar19)(DAT_23ed6cd28,plVar8);
                                                    *plVar8 = *plVar8 + -1;
                                                    if (*plVar8 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    if (plStack_1b0 != (longlong *)0x0) {
LAB_23e2cbae8:
                                                      plVar7 = (longlong *)FUN_23e8bc2f0();
                                                      if (plVar7 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar1 + 5) = 0x15e;
                                                        plVar8 = (longlong *)
                                                                 FUN_23e915840(lVar10,plVar7,
                                                                               _DAT_23eeada60);
                                                        *plVar7 = *plVar7 + -1;
                                                        if (*plVar7 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar8 != (longlong *)0x0) {
                                                          *plVar8 = *plVar8 + -1;
                                                          if (*plVar8 == 0) {
                                                            FUN_23a334bc0(plVar8);
                                                          }
                                                          plVar7 = (longlong *)
                                                                   FUN_23e8bc2f0(plVar24,
                                                  _DAT_23eeadb98);
                                                  if (plVar7 == (longlong *)0x0) {
LAB_23e2cbd3d:
                                                    auStack_120 = *(undefined1 (*) [8])
                                                                   (lVar10 + 0x60);
                                                    pcStack_118 = *(code **)(lVar10 + 0x68);
                                                    pcStack_110 = *(code **)(lVar10 + 0x70);
                                                    *(undefined8 *)(lVar10 + 0x70) = 0;
                                                    *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                         (undefined1  [16])0x0;
                                                  }
                                                  else {
                                                    plVar8 = (longlong *)
                                                             FUN_23e8bc2f0(plVar7,_DAT_23eead9b8);
                                                    *plVar7 = *plVar7 + -1;
                                                    if (*plVar7 == 0) {
                                                      FUN_23a334bc0();
                                                    }
                                                    plVar7 = _DAT_23eeadca8;
                                                    if (plVar8 == (longlong *)0x0)
                                                    goto LAB_23e2cbd3d;
                                                    plVar9 = (longlong *)
                                                             FUN_23e916ad0(*(undefined8 *)
                                                                            (lVar10 + 0x10),3);
                                                    *plVar7 = *plVar7 + 1;
                                                    plVar9[3] = (longlong)plVar7;
                                                    lVar14 = FUN_23e8f6680();
                                                    if (lVar14 == 0) {
                                                      FUN_23e915740(lVar10,auStack_120,DAT_23eeadd68
                                                                   );
LAB_23e2cbd05:
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                    }
                                                    else {
                                                      lVar14 = FUN_23e94f9d0(lVar10,lVar14,
                                                                             DAT_23ed6cd28);
                                                      if (lVar14 == 0) {
                                                        pcStack_110 = *(code **)(lVar10 + 0x70);
                                                        auStack_120 = *(undefined1 (*) [8])
                                                                       (lVar10 + 0x60);
                                                        pcStack_118 = *(code **)(lVar10 + 0x68);
                                                        *(undefined8 *)(lVar10 + 0x70) = 0;
                                                        *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                             (undefined1  [16])0x0;
                                                        goto LAB_23e2cbd05;
                                                      }
                                                      plVar9[4] = lVar14;
                                                      plVar7 = _DAT_23eeadcb8;
                                                      *_DAT_23eeadcb8 = *_DAT_23eeadcb8 + 1;
                                                      plVar9[5] = (longlong)plVar7;
                                                      plVar7 = (longlong *)
                                                               (*pcVar19)(DAT_23ed6cd28,plVar9);
                                                      *plVar9 = *plVar9 + -1;
                                                      if (*plVar9 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                      if (plVar7 != (longlong *)0x0) {
                                                        *(undefined4 *)(plVar1 + 5) = 0x15f;
                                                        plVar9 = (longlong *)
                                                                 FUN_23e914090(lVar10,plVar8);
                                                        *plVar8 = *plVar8 + -1;
                                                        if (*plVar8 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        *plVar7 = *plVar7 + -1;
                                                        if (*plVar7 == 0) {
                                                          FUN_23a334bc0();
                                                        }
                                                        if (plVar9 != (longlong *)0x0) {
                                                          *plVar9 = *plVar9 + -1;
                                                          if (*plVar9 == 0) {
                                                            FUN_23a334bc0(plVar9);
                                                          }
                                                          goto LAB_23e2c85c3;
                                                        }
                                                        goto LAB_23e2cbd3d;
                                                      }
                                                      auStack_120 = *(undefined1 (*) [8])
                                                                     (lVar10 + 0x60);
                                                      pcStack_118 = *(code **)(lVar10 + 0x68);
                                                      pcStack_110 = *(code **)(lVar10 + 0x70);
                                                      *(undefined8 *)(lVar10 + 0x70) = 0;
                                                      *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                           (undefined1  [16])0x0;
                                                      *plVar8 = *plVar8 + -1;
                                                      if (*plVar8 == 0) {
                                                        FUN_23a334bc0();
                                                      }
                                                    }
                                                  }
                                                  uVar23 = 0x15f;
                                                  goto LAB_23e2ca9dc;
                                                  }
                                                  }
                                                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60)
                                                  ;
                                                  pcStack_118 = *(code **)(lVar10 + 0x68);
                                                  pcStack_110 = *(code **)(lVar10 + 0x70);
                                                  *(undefined8 *)(lVar10 + 0x70) = 0;
                                                  uVar23 = 0x15e;
                                                  *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                  goto LAB_23e2ca9dc;
                                                  }
                                                  }
                                                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60)
                                                  ;
                                                  pcStack_118 = *(code **)(lVar10 + 0x68);
                                                  pcStack_110 = *(code **)(lVar10 + 0x70);
                                                  uVar23 = 0x15c;
                                                  *(undefined8 *)(lVar10 + 0x70) = 0;
                                                  *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                       (undefined1  [16])0x0;
                                                }
                                              }
                                            }
                                          }
                                        }
                                      }
                                    }
                                  }
                                  else {
                                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb98);
                                    if (plVar7 == (longlong *)0x0) {
                                      auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                      pcStack_118 = *(code **)(lVar10 + 0x68);
                                      pcStack_110 = *(code **)(lVar10 + 0x70);
                                      uVar23 = 0x161;
                                      *(undefined8 *)(lVar10 + 0x70) = 0;
                                      plStack_1b0 = (longlong *)0x0;
                                      plStack_1a8 = (longlong *)0x0;
                                      plStack_1d0 = (longlong *)0x0;
                                      *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                                      plStack_1d8 = (longlong *)0x0;
                                    }
                                    else {
                                      *(undefined4 *)(plVar1 + 5) = 0x161;
                                      plVar8 = (longlong *)
                                               FUN_23e915840(lVar10,plVar7,_DAT_23eeada60);
                                      lVar14 = *plVar7;
                                      *plVar7 = lVar14 + -1;
                                      if (lVar14 + -1 == 0) {
                                        FUN_23a334bc0();
                                      }
                                      if (plVar8 == (longlong *)0x0) {
                                        auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                        pcStack_118 = *(code **)(lVar10 + 0x68);
                                        pcStack_110 = *(code **)(lVar10 + 0x70);
                                        uVar23 = 0x161;
                                        *(undefined8 *)(lVar10 + 0x70) = 0;
                                        plStack_1b0 = (longlong *)0x0;
                                        plStack_1a8 = (longlong *)0x0;
                                        plStack_1d8 = (longlong *)0x0;
                                        *(undefined1 (*) [16])(lVar10 + 0x60) =
                                             (undefined1  [16])0x0;
                                        plStack_1d0 = (longlong *)0x0;
                                      }
                                      else {
                                        lVar14 = *plVar8;
                                        *plVar8 = lVar14 + -1;
                                        if (lVar14 + -1 == 0) {
                                          FUN_23a334bc0(plVar8);
                                        }
                                        plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb98);
                                        if (plVar7 == (longlong *)0x0) {
LAB_23e2cb832:
                                          auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                          pcStack_118 = *(code **)(lVar10 + 0x68);
                                          pcStack_110 = *(code **)(lVar10 + 0x70);
                                          *(undefined8 *)(lVar10 + 0x70) = 0;
                                          *(undefined1 (*) [16])(lVar10 + 0x60) =
                                               (undefined1  [16])0x0;
                                        }
                                        else {
                                          plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eead9b8);
                                          *plVar7 = *plVar7 + -1;
                                          if (*plVar7 == 0) {
                                            FUN_23a334bc0();
                                          }
                                          plVar7 = _DAT_23eeadca8;
                                          if (plVar8 == (longlong *)0x0) goto LAB_23e2cb832;
                                          plVar9 = (longlong *)
                                                   FUN_23e916ad0(*(undefined8 *)(lVar10 + 0x10),3);
                                          *plVar7 = *plVar7 + 1;
                                          plVar9[3] = (longlong)plVar7;
                                          lVar14 = FUN_23e8f6530();
                                          if (lVar14 == 0) {
                                            FUN_23e915740(lVar10,auStack_120,DAT_23eeadd28);
LAB_23e2cb7fa:
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0();
                                            }
                                          }
                                          else {
                                            lVar14 = FUN_23e94f9d0(lVar10,lVar14,DAT_23ed6cd28);
                                            if (lVar14 == 0) {
                                              pcStack_110 = *(code **)(lVar10 + 0x70);
                                              auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                              pcStack_118 = *(code **)(lVar10 + 0x68);
                                              *(undefined8 *)(lVar10 + 0x70) = 0;
                                              *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                   (undefined1  [16])0x0;
                                              goto LAB_23e2cb7fa;
                                            }
                                            plVar9[4] = lVar14;
                                            plVar7 = _DAT_23eeadcb8;
                                            *_DAT_23eeadcb8 = *_DAT_23eeadcb8 + 1;
                                            plVar9[5] = (longlong)plVar7;
                                            plVar7 = (longlong *)(*pcVar19)(DAT_23ed6cd28,plVar9);
                                            *plVar9 = *plVar9 + -1;
                                            if (*plVar9 == 0) {
                                              FUN_23a334bc0();
                                            }
                                            if (plVar7 != (longlong *)0x0) {
                                              *(undefined4 *)(plVar1 + 5) = 0x162;
                                              plVar9 = (longlong *)FUN_23e914090(lVar10,plVar8);
                                              *plVar8 = *plVar8 + -1;
                                              if (*plVar8 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              *plVar7 = *plVar7 + -1;
                                              if (*plVar7 == 0) {
                                                FUN_23a334bc0();
                                              }
                                              if (plVar9 != (longlong *)0x0) {
                                                *plVar9 = *plVar9 + -1;
                                                if (*plVar9 == 0) {
                                                  FUN_23a334bc0(plVar9);
                                                  plStack_1b0 = (longlong *)0x0;
                                                  plStack_1a8 = (longlong *)0x0;
                                                  plStack_1d8 = (longlong *)0x0;
                                                  plStack_1d0 = (longlong *)0x0;
                                                }
                                                else {
                                                  plStack_1b0 = (longlong *)0x0;
                                                  plStack_1a8 = (longlong *)0x0;
                                                  plStack_1d8 = (longlong *)0x0;
                                                  plStack_1d0 = (longlong *)0x0;
                                                }
                                                goto LAB_23e2c85c3;
                                              }
                                              goto LAB_23e2cb832;
                                            }
                                            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                                            pcStack_118 = *(code **)(lVar10 + 0x68);
                                            pcStack_110 = *(code **)(lVar10 + 0x70);
                                            *(undefined8 *)(lVar10 + 0x70) = 0;
                                            *(undefined1 (*) [16])(lVar10 + 0x60) =
                                                 (undefined1  [16])0x0;
                                            *plVar8 = *plVar8 + -1;
                                            if (*plVar8 == 0) {
                                              FUN_23a334bc0();
                                            }
                                          }
                                        }
                                        uVar23 = 0x162;
                                        plStack_1b0 = (longlong *)0x0;
                                        plStack_1a8 = (longlong *)0x0;
                                        plStack_1d8 = (longlong *)0x0;
                                        plStack_1d0 = (longlong *)0x0;
                                      }
                                    }
                                  }
                                }
                              }
                              goto LAB_23e2ca9dc;
                            }
                            pcStack_110 = *(code **)(lVar10 + 0x70);
                            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                            pcStack_118 = *(code **)(lVar10 + 0x68);
                            *(undefined8 *)(lVar10 + 0x70) = 0;
                            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                          }
                          else {
                            iVar6 = *(int *)(lVar14 + 0xc);
                            if (*(int *)(lVar14 + 0xc) == 0) {
                              *(int *)(lVar14 + 0xc) = _DAT_23ec14e6c;
                              iVar6 = _DAT_23ec14e6c;
                              _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
                            }
                            if (_DAT_23ec14e58 != iVar6) {
                              _DAT_23ec14e58 = iVar6;
                              _DAT_23eeb02c8 =
                                   FUN_23e8cbd60(lVar14,DAT_23eeaddd0,
                                                 *(undefined8 *)(DAT_23eeaddd0 + 0x18));
                            }
                            if (-1 < _DAT_23eeb02c8) {
                              lVar3 = lVar14 + 0x20 + (1L << (*(byte *)(lVar14 + 9) & 0x3f));
                              lVar20 = *(longlong *)(lVar3 + 8 + _DAT_23eeb02c8 * 0x10);
                              if (lVar20 != 0) goto LAB_23e2c82a2;
                              _DAT_23eeb02c8 =
                                   FUN_23e8cbd60(lVar14,DAT_23eeaddd0,
                                                 *(undefined8 *)(DAT_23eeaddd0 + 0x18));
                              if (-1 < _DAT_23eeb02c8) {
                                lVar20 = *(longlong *)(lVar3 + 8 + _DAT_23eeb02c8 * 0x10);
                                goto LAB_23e2cc3c2;
                              }
                            }
LAB_23e2cc3cb:
                            plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeaddd0);
                            if ((plVar8 != (longlong *)0x0) && (lVar20 = *plVar8, lVar20 != 0))
                            goto LAB_23e2c82a2;
                            FUN_23e915740(lVar10,auStack_120,DAT_23eeaddd0);
                          }
                          lVar14 = *plVar7;
                          *plVar7 = lVar14 + -1;
                          if (lVar14 + -1 == 0) {
                            FUN_23a334bc0();
                          }
                        }
LAB_23e2cc30e:
                        uVar23 = 0x14f;
                        plStack_1b0 = (longlong *)0x0;
                        plStack_1a8 = (longlong *)0x0;
                        plStack_1d8 = (longlong *)0x0;
                        plStack_1d0 = (longlong *)0x0;
                        plStack_1c8 = (longlong *)0x0;
                        plStack_1c0 = (longlong *)0x0;
                      }
                    }
                  }
                }
              }
            }
LAB_23e2ca9dc:
            pcVar12 = pcStack_110;
            pcStack_110 = (code *)0x0;
            pcStack_130 = pcVar12;
            plVar7 = *(longlong **)(lVar10 + 0x138);
            plStack_140 = (longlong *)auStack_120;
            pcStack_138 = pcStack_118;
            auStack_120 = (undefined1  [8])0x0;
            pcStack_118 = (code *)0x0;
            if (plVar7 != (longlong *)0x0) {
              *plVar7 = *plVar7 + 1;
            }
            if (pcVar12 == (code *)0x0) {
              lVar14 = FUN_23e8d6280(plVar1,uVar23);
            }
            else {
              lVar14 = FUN_23e8d6280(plVar1,uVar23);
              *(code **)(lVar14 + 0x10) = pcVar12;
              *(longlong *)pcVar12 = *(longlong *)pcVar12 + 1;
            }
            if ((pcStack_130 != (code *)0x0) &&
               (*(longlong *)pcStack_130 = *(longlong *)pcStack_130 + -1,
               *(longlong *)pcStack_130 == 0)) {
              FUN_23a334bc0();
            }
            pcStack_130 = (code *)lVar14;
            FUN_23a35ef40(lVar10,pplStack_190);
            iVar6 = FUN_23a35ebd0(lVar10,*(undefined8 *)(*(longlong *)(lVar10 + 0x138) + 8),
                                  *(undefined8 *)PyExc_Exception_exref);
            if (iVar6 == 0) {
              cVar5 = FUN_23e8ba320(*(undefined8 *)(lVar10 + 0x138),auStack_120);
              iVar6 = 0;
              if (cVar5 == '\0') {
                iVar6 = 0x13f;
              }
              pcVar12 = pcStack_110;
              auVar22 = auStack_120;
              pcVar19 = pcStack_118;
              if ((pcStack_110 != (code *)0x0) && (*(longlong **)(pcStack_110 + 0x18) == plVar1)) {
                *(undefined4 *)(plVar1 + 5) = *(undefined4 *)(pcStack_110 + 0x24);
              }
            }
            else {
              plVar8 = *(longlong **)(lVar10 + 0x138);
              *plVar8 = *plVar8 + 1;
              lVar14 = FUN_23e8f6a70();
              if (lVar14 == 0) {
                FUN_23e915740(lVar10,auStack_120,DAT_23eeadcf8);
LAB_23e2cae03:
                iVar6 = 0x165;
              }
              else {
                plVar11 = (longlong *)FUN_23e8bc2f0(lVar14,_DAT_23eeade28);
                plVar9 = _DAT_23eeade30;
                if (plVar11 == (longlong *)0x0) {
LAB_23e2caea1:
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23e2cae03;
                }
                plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(lVar10 + 0x10),2);
                *plVar9 = *plVar9 + 1;
                plVar16[3] = (longlong)plVar9;
                lVar14 = FUN_23e94f9d0(lVar10,plVar8,DAT_23ed6cd28);
                if (lVar14 == 0) {
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  *plVar16 = *plVar16 + -1;
                  if (*plVar16 == 0) {
                    FUN_23a334bc0(plVar16);
                  }
                  goto LAB_23e2cae03;
                }
                plVar16[4] = lVar14;
                plVar9 = (longlong *)(*pcVar19)(DAT_23ed6cd28,plVar16);
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0(plVar16);
                }
                if (plVar9 == (longlong *)0x0) {
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  goto LAB_23e2cae03;
                }
                *(undefined4 *)(plVar1 + 5) = 0x165;
                plVar16 = (longlong *)FUN_23e914090(lVar10,plVar11);
                *plVar11 = *plVar11 + -1;
                if (*plVar11 == 0) {
                  FUN_23a334bc0(plVar11);
                }
                *plVar9 = *plVar9 + -1;
                if (*plVar9 == 0) {
                  FUN_23a334bc0(plVar9);
                }
                if (plVar16 == (longlong *)0x0) goto LAB_23e2caea1;
                *plVar16 = *plVar16 + -1;
                if (*plVar16 == 0) {
                  FUN_23a334bc0(plVar16);
                }
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb88);
                if (plVar9 == (longlong *)0x0) {
LAB_23e2caf1b:
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  iVar6 = 0x166;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                }
                else {
                  *(undefined4 *)(plVar1 + 5) = 0x166;
                  plVar11 = (longlong *)FUN_23e915840(lVar10,plVar9,_DAT_23eeada60,plVar15);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    FUN_23a334bc0(plVar9);
                  }
                  if (plVar11 == (longlong *)0x0) goto LAB_23e2caf1b;
                  *plVar11 = *plVar11 + -1;
                  if (*plVar11 == 0) {
                    FUN_23a334bc0(plVar11);
                  }
                  plVar9 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb98);
                  if (plVar9 != (longlong *)0x0) {
                    *(undefined4 *)(plVar1 + 5) = 0x167;
                    plVar11 = (longlong *)FUN_23e915840(lVar10,plVar9);
                    *plVar9 = *plVar9 + -1;
                    if (*plVar9 == 0) {
                      FUN_23a334bc0(plVar9);
                    }
                    if (plVar11 != (longlong *)0x0) {
                      *plVar11 = *plVar11 + -1;
                      if (*plVar11 == 0) {
                        FUN_23a334bc0(plVar11);
                      }
                      *plVar8 = *plVar8 + -1;
                      if (*plVar8 == 0) {
                        FUN_23a334bc0(plVar8);
                      }
                      FUN_23ebf6ae0(lVar10,plVar7);
                      goto LAB_23e2c85c3;
                    }
                  }
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  iVar6 = 0x167;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                }
              }
              pcVar12 = pcStack_110;
              pcVar19 = pcStack_118;
              auVar22 = auStack_120;
              _auStack_120 = (undefined1  [16])0x0;
              pcStack_110 = (code *)0x0;
              *plVar8 = *plVar8 + -1;
              if (*plVar8 == 0) {
                FUN_23a334bc0(plVar8);
              }
            }
            pcStack_118 = pcVar19;
            auStack_120 = auVar22;
            pcVar19 = pcStack_118;
            auVar22 = auStack_120;
            pcStack_110 = (code *)0x0;
            _auStack_120 = (undefined1  [16])0x0;
            FUN_23ebf6ae0(lVar10,plVar7);
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            pcStack_110 = pcVar12;
            auStack_120 = auVar22;
            pcStack_118 = pcVar19;
            goto LAB_23e2c6ef9;
          }
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb88);
          lVar14 = _DAT_23eeadd38;
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x169;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1b8 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x169;
          plVar8 = (longlong *)
                   FUN_23e915840(lVar10,plVar7,_DAT_23eeada60,*(undefined8 *)(lVar14 + 0x18));
          lVar14 = *plVar7;
          *plVar7 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            FUN_23a334bc0();
          }
          if (plVar8 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x169;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1e0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          lVar14 = *plVar8;
          *plVar8 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            FUN_23a334bc0(plVar8);
          }
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadb98);
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x16a;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1e0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1b8 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          *(undefined4 *)(plVar1 + 5) = 0x16a;
          plVar8 = (longlong *)FUN_23e915840();
          lVar14 = *plVar7;
          *plVar7 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            FUN_23a334bc0();
          }
          if (plVar8 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x16a;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            pplStack_190 = (longlong **)0x0;
            plStack_1b0 = (longlong *)0x0;
            plStack_1a8 = (longlong *)0x0;
            plStack_1d8 = (longlong *)0x0;
            plStack_1d0 = (longlong *)0x0;
            plStack_1c8 = (longlong *)0x0;
            plStack_1c0 = (longlong *)0x0;
            plStack_198 = (longlong *)0x0;
            plStack_1b8 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1e0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          lVar14 = *plVar8;
          *plVar8 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            FUN_23a334bc0(plVar8);
          }
          plStack_1b0 = (longlong *)0x0;
          plStack_1a8 = (longlong *)0x0;
          plStack_1d8 = (longlong *)0x0;
          plStack_1d0 = (longlong *)0x0;
          plStack_1c8 = (longlong *)0x0;
          plStack_1c0 = (longlong *)0x0;
          plStack_198 = (longlong *)0x0;
          plStack_1b8 = (longlong *)0x0;
          plStack_1e0 = (longlong *)0x0;
LAB_23e2c85c3:
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eead900);
          if (plVar7 == (longlong *)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x16d;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            pplStack_190 = (longlong **)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            plStack_1a0 = (longlong *)0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          pplStack_190 = (longlong **)FUN_23e8bc2f0(plVar7,_DAT_23eeadd18);
          lVar14 = *plVar7;
          *plVar7 = lVar14 + -1;
          if (lVar14 + -1 == 0) {
            FUN_23a334bc0();
          }
          if (pplStack_190 == (longlong **)0x0) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x16d;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          iVar6 = FUN_23a35f020();
          if (iVar6 == -1) {
LAB_23e2cb68f:
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            iVar6 = 0x16e;
            *(undefined8 *)(lVar10 + 0x70) = 0;
            plStack_1a0 = (longlong *)0x0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            pcStack_118 = *(code **)(lVar10 + 0x68);
            goto LAB_23e2c6ef9;
          }
          if (iVar6 != 0) {
            plVar7 = (longlong *)FUN_23e8bd600(lVar10,pplStack_190);
            if (plVar7 != (longlong *)0x0) {
              cVar5 = FUN_23e8d1960(plVar7,8);
              *plVar7 = *plVar7 + -1;
              if (*plVar7 == 0) {
                FUN_23a334bc0(plVar7);
              }
              if (cVar5 == '\0') goto LAB_23e2c8650;
              plVar7 = (longlong *)FUN_23a38cc10(lVar10,pplStack_190,_DAT_23eeade38);
              if (plVar7 == (longlong *)0x0) {
LAB_23e2cb351:
                auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                pcStack_118 = *(code **)(lVar10 + 0x68);
                pcStack_110 = *(code **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
              }
              else {
                lVar14 = FUN_23e94f9d0(lVar10,plVar7,DAT_23ed6cd28);
                *plVar7 = *plVar7 + -1;
                if (*plVar7 == 0) {
                  FUN_23a334bc0();
                }
                if (lVar14 == 0) {
                  auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                  pcStack_110 = *(code **)(lVar10 + 0x70);
                  iVar6 = 0x16f;
                  *(undefined8 *)(lVar10 + 0x70) = 0;
                  *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                  plStack_1a0 = (longlong *)0x0;
                  pcStack_118 = *(code **)(lVar10 + 0x68);
                  goto LAB_23e2c6ef9;
                }
                plVar8 = (longlong *)FUN_23e916ad0(*(undefined8 *)(lVar10 + 0x10),3);
                uVar23 = _DAT_23eeade48;
                plVar8[3] = lVar14;
                plVar7 = _DAT_23eeade40;
                *_DAT_23eeade40 = *_DAT_23eeade40 + 1;
                plVar8[4] = (longlong)plVar7;
                plVar7 = (longlong *)FUN_23a38cc10(lVar10,pplStack_190,uVar23);
                if (plVar7 != (longlong *)0x0) {
                  lVar14 = FUN_23e94f9d0(lVar10,plVar7,DAT_23ed6cd28);
                  *plVar7 = *plVar7 + -1;
                  if (*plVar7 == 0) {
                    FUN_23a334bc0();
                  }
                  if (lVar14 != 0) {
                    plVar8[5] = lVar14;
                    plStack_1a0 = (longlong *)(*pcVar19)(DAT_23ed6cd28,plVar8);
                    *plVar8 = *plVar8 + -1;
                    if (*plVar8 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plStack_1a0 == (longlong *)0x0) goto LAB_23e2cb351;
                    plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadba8);
                    if (plVar7 != (longlong *)0x0) {
                      *(undefined4 *)(plVar1 + 5) = 0x170;
                      plVar8 = (longlong *)FUN_23e915840(lVar10,plVar7,_DAT_23eeada60,plStack_1a0);
                      *plVar7 = *plVar7 + -1;
                      if (*plVar7 == 0) {
                        FUN_23a334bc0();
                      }
                      if (plVar8 != (longlong *)0x0) {
                        *plVar8 = *plVar8 + -1;
                        pcVar19 = _Py_NoneStruct_exref;
                        if (*plVar8 == 0) {
                          FUN_23a334bc0(plVar8);
                          pcVar19 = _Py_NoneStruct_exref;
                        }
                        goto LAB_23e2c730b;
                      }
                    }
                    auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                    pcStack_110 = *(code **)(lVar10 + 0x70);
                    iVar6 = 0x170;
                    *(undefined8 *)(lVar10 + 0x70) = 0;
                    *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                    pcStack_118 = *(code **)(lVar10 + 0x68);
                    goto LAB_23e2c6ef9;
                  }
                }
                auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
                pcStack_118 = *(code **)(lVar10 + 0x68);
                pcStack_110 = *(code **)(lVar10 + 0x70);
                *(undefined8 *)(lVar10 + 0x70) = 0;
                *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
                *plVar8 = *plVar8 + -1;
                if (*plVar8 == 0) {
                  FUN_23a334bc0();
                }
              }
              iVar6 = 0x16f;
              plStack_1a0 = (longlong *)0x0;
              goto LAB_23e2c6ef9;
            }
            goto LAB_23e2cb68f;
          }
LAB_23e2c8650:
          plVar7 = (longlong *)FUN_23e8bc2f0(plVar24,_DAT_23eeadba8);
          if (plVar7 == (longlong *)0x0) {
LAB_23e2cb0b4:
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
LAB_23e2cb09e:
            iVar6 = 0x172;
            plStack_1a0 = (longlong *)0x0;
            goto LAB_23e2c6ef9;
          }
          plVar8 = (longlong *)FUN_23e8bc2f0(plVar7,_DAT_23eeada60);
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0();
          }
          if (plVar8 == (longlong *)0x0) goto LAB_23e2cb0b4;
          iVar6 = FUN_23a35f020();
          if (iVar6 == -1) {
            auStack_120 = *(undefined1 (*) [8])(lVar10 + 0x60);
            pcStack_118 = *(code **)(lVar10 + 0x68);
            pcStack_110 = *(code **)(lVar10 + 0x70);
            *(undefined8 *)(lVar10 + 0x70) = 0;
            *(undefined1 (*) [16])(lVar10 + 0x60) = (undefined1  [16])0x0;
            *plVar8 = *plVar8 + -1;
            if (*plVar8 == 0) {
              FUN_23a334bc0();
            }
            goto LAB_23e2cb09e;
          }
          *(undefined4 *)(plVar1 + 5) = 0x172;
          plVar7 = (longlong *)FUN_23e914090();
          *plVar8 = *plVar8 + -1;
          if (*plVar8 == 0) {
            FUN_23a334bc0();
          }
          if (plVar7 == (longlong *)0x0) goto LAB_23e2cb0b4;
          *plVar7 = *plVar7 + -1;
          if (*plVar7 == 0) {
            FUN_23a334bc0(plVar7);
            plStack_1a0 = (longlong *)0x0;
            pcVar19 = _Py_NoneStruct_exref;
          }
          else {
            plStack_1a0 = (longlong *)0x0;
            pcVar19 = _Py_NoneStruct_exref;
          }
LAB_23e2c730b:
          lVar14 = *(longlong *)(*(longlong *)(lVar10 + 0x38) + 8);
          plVar1 = *(longlong **)(lVar14 + 0x28);
          plVar7 = (longlong *)plVar1[2];
          *(undefined8 *)(*(longlong *)(lVar10 + 0x38) + 8) = *(undefined8 *)(lVar14 + 0x30);
          *(undefined4 *)(plVar1 + 8) = 0xffffffff;
          if (plVar7 != (longlong *)0x0) {
            plVar1[2] = 0;
            *plVar7 = *plVar7 + -1;
            if (*plVar7 == 0) {
              (**(code **)(plVar7[1] + 0x30))();
            }
          }
          *plVar1 = *plVar1 + -1;
          if (*plVar1 == 0) {
            (**(code **)(plVar1[1] + 0x30))(plVar1);
          }
          *(longlong *)pcVar19 = *(longlong *)pcVar19 + 1;
          plVar1[0xf] = 0;
          if ((plVar13 != (longlong *)0x0) && (*plVar13 = *plVar13 + -1, *plVar13 == 0)) {
            (**(code **)(plVar13[1] + 0x30))(plVar13);
          }
          if ((plVar15 != (longlong *)0x0) && (*plVar15 = *plVar15 + -1, *plVar15 == 0)) {
            (**(code **)(plVar15[1] + 0x30))(plVar15);
          }
          if ((plStack_1e0 != (longlong *)0x0) &&
             (lVar10 = *plStack_1e0, *plStack_1e0 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1e0[1] + 0x30))(plStack_1e0);
          }
          if ((plStack_1b8 != (longlong *)0x0) &&
             (lVar10 = *plStack_1b8, *plStack_1b8 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1b8[1] + 0x30))(plStack_1b8);
          }
          if ((plStack_198 != (longlong *)0x0) &&
             (lVar10 = *plStack_198, *plStack_198 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_198[1] + 0x30))(plStack_198);
          }
          if ((plStack_1c0 != (longlong *)0x0) &&
             (lVar10 = *plStack_1c0, *plStack_1c0 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1c0[1] + 0x30))(plStack_1c0);
          }
          if ((plStack_1c8 != (longlong *)0x0) &&
             (lVar10 = *plStack_1c8, *plStack_1c8 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1c8[1] + 0x30))(plStack_1c8);
          }
          if ((plStack_1d0 != (longlong *)0x0) &&
             (lVar10 = *plStack_1d0, *plStack_1d0 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1d0[1] + 0x30))(plStack_1d0);
          }
          if ((plStack_1d8 != (longlong *)0x0) &&
             (lVar10 = *plStack_1d8, *plStack_1d8 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1d8[1] + 0x30))(plStack_1d8);
          }
          if ((plStack_1a8 != (longlong *)0x0) &&
             (lVar10 = *plStack_1a8, *plStack_1a8 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1a8[1] + 0x30))(plStack_1a8);
          }
          if ((plStack_1b0 != (longlong *)0x0) &&
             (lVar10 = *plStack_1b0, *plStack_1b0 = lVar10 + -1, lVar10 + -1 == 0)) {
            (**(code **)(plStack_1b0[1] + 0x30))(plStack_1b0);
          }
          if ((pplStack_190 != (longlong **)0x0) &&
             (lVar10 = (longlong)*pplStack_190, *pplStack_190 = (longlong *)(lVar10 + -1),
             lVar10 + -1 == 0)) {
            (**(code **)((longlong)pplStack_190[1] + 0x30))(pplStack_190);
          }
        }
        if ((plStack_1a0 != (longlong *)0x0) &&
           (lVar10 = *plStack_1a0, *plStack_1a0 = lVar10 + -1, lVar10 + -1 == 0)) {
          (**(code **)(plStack_1a0[1] + 0x30))(plStack_1a0);
        }
LAB_23e2c6dfb:
        lVar10 = *plVar24;
        *plVar24 = lVar10 + -1;
        if (lVar10 + -1 == 0) {
          (**(code **)(plVar24[1] + 0x30))(plVar24);
        }
        return pcVar19;
      }
      *plVar11 = *plVar11 + 1;
      DAT_23ed6a4c0 = plVar11;
    }
    pcStack_70 = pcVar19;
    puStack_b0 = (undefined8 *)0x23e2c60e4;
    plStack_78 = plVar1;
    lVar10 = FUN_23e94ed00(param_1,plVar11,&plStack_78);
    if (lVar10 != 0) {
      plVar7[4] = lVar10;
      puStack_b0 = (undefined8 *)0x23e2c60fe;
      plVar8 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar7);
      *plVar7 = *plVar7 + -1;
      if (*plVar7 == 0) {
        puStack_b0 = (undefined8 *)0x23e2c655a;
        (**(code **)(plVar7[1] + 0x30))(plVar7);
      }
      if (plVar8 == (longlong *)0x0) {
        pcStack_88 = *(code **)(param_1 + 0x68);
        plVar8 = *(longlong **)(param_1 + 0x60);
        pcVar19 = *(code **)(param_1 + 0x70);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        *(undefined8 *)(param_1 + 0x70) = 0;
        *plVar9 = *plVar9 + -1;
        pcVar12 = DAT_23ed6a4f8;
        uVar4 = uStack_7c;
        uVar21 = 0x11f;
        if (*plVar9 == 0) {
          uStack_7c = 0x11f;
          puStack_b0 = (undefined8 *)0x23e2c67ee;
          (**(code **)(plVar9[1] + 0x30))(plVar9);
          pcVar12 = DAT_23ed6a4f8;
          uVar4 = uStack_7c;
          uVar21 = uStack_7c;
        }
        goto joined_r0x00023e2c64ac;
      }
      *(undefined4 *)(plVar15 + 5) = 0x11f;
      puStack_b0 = (undefined8 *)0x23e2c6129;
      plVar7 = (longlong *)FUN_23e914090(param_1,plVar9,plVar8);
      *plVar9 = *plVar9 + -1;
      if (*plVar9 == 0) {
        puStack_b0 = (undefined8 *)0x23e2c613c;
        (**(code **)(plVar9[1] + 0x30))(plVar9);
      }
      *plVar8 = *plVar8 + -1;
      if (*plVar8 == 0) {
        puStack_b0 = (undefined8 *)0x23e2c656a;
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar7 != (longlong *)0x0) {
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_b0 = (undefined8 *)0x23e2c6160;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
        plVar7 = *(longlong **)(lVar10 + 0x28);
        plVar15 = (longlong *)plVar7[2];
        *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
        *(undefined4 *)(plVar7 + 8) = 0xffffffff;
        if (plVar15 != (longlong *)0x0) {
          plVar7[2] = 0;
          *plVar15 = *plVar15 + -1;
          if (*plVar15 == 0) {
            puStack_b0 = (undefined8 *)0x23e2c6199;
            (**(code **)(plVar15[1] + 0x30))();
          }
        }
        *plVar7 = *plVar7 + -1;
        if (*plVar7 == 0) {
          puStack_b0 = (undefined8 *)0x23e2c61a9;
          (**(code **)(plVar7[1] + 0x30))(plVar7);
        }
        plVar7[0xf] = 0;
        pcVar19 = _Py_NoneStruct_exref;
        *(longlong *)_Py_NoneStruct_exref = *(longlong *)_Py_NoneStruct_exref + 1;
        *plVar13 = *plVar13 + -1;
        if (*plVar13 == 0) {
          puStack_b0 = (undefined8 *)0x23e2c61ce;
          (**(code **)(plVar13[1] + 0x30))(plVar13);
        }
        *plVar1 = *plVar1 + -1;
        if (*plVar1 != 0) {
          return pcVar19;
        }
        puStack_b0 = (undefined8 *)0x23e2c657a;
        (**(code **)(plVar1[1] + 0x30))(plVar1);
        return pcVar19;
      }
      goto LAB_23e2c65f0;
    }
    pcStack_88 = *(code **)(param_1 + 0x68);
    plVar8 = *(longlong **)(param_1 + 0x60);
    pcVar19 = *(code **)(param_1 + 0x70);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    *(undefined8 *)(param_1 + 0x70) = 0;
    *plVar9 = *plVar9 + -1;
    if (*plVar9 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c6681;
      (**(code **)(plVar9[1] + 0x30))(plVar9);
    }
    *plVar7 = *plVar7 + -1;
    lVar10 = *plVar7;
    uVar21 = 0x11f;
    uVar4 = uStack_7c;
    uStack_7c = 0x11f;
  }
  else {
    iVar6 = *(int *)(lVar10 + 0xc);
    if (*(int *)(lVar10 + 0xc) == 0) {
      *(int *)(lVar10 + 0xc) = _DAT_23ec14e6c;
      iVar6 = _DAT_23ec14e6c;
      _DAT_23ec14e6c = _DAT_23ec14e6c + 1;
    }
    if (_DAT_23ec14e60 != iVar6) {
      puStack_b0 = (undefined8 *)0x23e2c6429;
      _DAT_23ec14e60 = iVar6;
      _DAT_23eeb02e8 = FUN_23e8cbd60(lVar10,DAT_23eeadcf0,*(undefined8 *)(DAT_23eeadcf0 + 0x18));
    }
    if (-1 < _DAT_23eeb02e8) {
      lVar20 = lVar10 + 0x20 + (1L << (*(byte *)(lVar10 + 9) & 0x3f));
      lVar14 = *(longlong *)(lVar20 + 8 + _DAT_23eeb02e8 * 0x10);
      if (lVar14 != 0) goto LAB_23e2c5f8c;
      puStack_b0 = (undefined8 *)0x23e2c6813;
      _DAT_23eeb02e8 = FUN_23e8cbd60(lVar10,DAT_23eeadcf0,*(undefined8 *)(DAT_23eeadcf0 + 0x18));
      if (-1 < _DAT_23eeb02e8) {
        lVar14 = *(longlong *)(lVar20 + 8 + _DAT_23eeb02e8 * 0x10);
        goto LAB_23e2c66d8;
      }
    }
LAB_23e2c6439:
    puStack_b0 = (undefined8 *)0x23e2c644f;
    plVar8 = (longlong *)FUN_23a37a020(DAT_23ed6ccc0,DAT_23eeadcf0);
    if ((plVar8 != (longlong *)0x0) && (lVar14 = *plVar8, lVar14 != 0)) goto LAB_23e2c5f8c;
    puStack_b0 = (undefined8 *)0x23e2c6474;
    FUN_23e915740(param_1,&plStack_78,DAT_23eeadcf0);
    pcStack_88 = pcStack_70;
    plVar8 = plStack_78;
LAB_23e2c6488:
    *plVar7 = *plVar7 + -1;
    lVar10 = *plVar7;
    uVar21 = 0x11e;
    pcVar19 = pcStack_68;
    uVar4 = uStack_7c;
    uStack_7c = 0x11e;
  }
  pcVar12 = DAT_23ed6a4f8;
  if (lVar10 == 0) {
    puStack_b0 = (undefined8 *)0x23e2c64a5;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
    pcVar12 = DAT_23ed6a4f8;
    uVar4 = uStack_7c;
    uVar21 = uStack_7c;
  }
joined_r0x00023e2c64ac:
  uStack_7c = uVar21;
  DAT_23ed6a4f8 = pcVar12;
  if (pcVar19 == (code *)0x0) {
    if (pcVar12 == (code *)0x0) {
      puStack_b0 = (undefined8 *)0x23e2c6848;
      pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
      uVar4 = uStack_7c;
      uVar21 = uStack_7c;
    }
    else {
      DAT_23ed6a4f8 = *(code **)pcVar12;
      *(longlong *)pcVar12 = 1;
      DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
      uVar21 = uStack_7c;
    }
    uStack_7c = uVar4;
    pcVar19 = _PyRuntime_exref;
    *(longlong *)(pcVar12 + 0x10) = 0;
    *(longlong **)(pcVar12 + 0x18) = plVar15;
    *plVar15 = *plVar15 + 1;
    lVar10 = *(longlong *)(pcVar19 + 0x1f8);
    *(undefined4 *)(pcVar12 + 0x24) = uVar21;
    lVar10 = *(longlong *)(lVar10 + 0x10);
    *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
    lVar10 = *(longlong *)(lVar10 + 0x2e8);
    lVar14 = *(longlong *)(pcVar12 + -8);
    puVar2 = *(undefined8 **)(lVar10 + 8);
    *puVar2 = pcVar12 + -0x10;
    *(longlong *)(pcVar12 + -0x10) = lVar10;
    *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
    *(code **)(lVar10 + 8) = pcVar12 + -0x10;
    pcVar18 = pcVar12;
    uVar4 = uStack_7c;
  }
  else {
    pcVar18 = pcVar19;
    if (*(longlong **)(pcVar19 + 0x18) != plVar15) {
      if (pcVar12 == (code *)0x0) {
        puStack_b0 = (undefined8 *)0x23e2c6730;
        pcVar12 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
        uVar4 = uStack_7c;
        uVar21 = uStack_7c;
      }
      else {
        DAT_23ed6a4f8 = *(code **)pcVar12;
        *(longlong *)pcVar12 = 1;
        DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
        uVar21 = uStack_7c;
      }
      uStack_7c = uVar4;
      pcVar18 = _PyRuntime_exref;
      *(longlong **)(pcVar12 + 0x18) = plVar15;
      *plVar15 = *plVar15 + 1;
      lVar10 = *(longlong *)(pcVar18 + 0x1f8);
      *(undefined4 *)(pcVar12 + 0x24) = uVar21;
      *(undefined4 *)(pcVar12 + 0x20) = 0xffffffff;
      lVar10 = *(longlong *)(*(longlong *)(lVar10 + 0x10) + 0x2e8);
      lVar14 = *(longlong *)(pcVar12 + -8);
      puVar2 = *(undefined8 **)(lVar10 + 8);
      *puVar2 = pcVar12 + -0x10;
      *(longlong *)(pcVar12 + -0x10) = lVar10;
      *(ulonglong *)(pcVar12 + -8) = (ulonglong)((uint)lVar14 & 3) | (ulonglong)puVar2;
      lVar14 = *(longlong *)pcVar19;
      *(code **)(lVar10 + 8) = pcVar12 + -0x10;
      *(code **)(pcVar12 + 0x10) = pcVar19;
      pcVar18 = pcVar12;
      uVar4 = uStack_7c;
      if (lVar14 == 0) {
        puStack_b0 = (undefined8 *)0x23e2c6327;
        (**(code **)(*(longlong *)(pcVar19 + 8) + 0x30))(pcVar19);
        uVar4 = uStack_7c;
      }
    }
  }
  uStack_7c = uVar4;
  puStack_b0 = (undefined8 *)0x23e2c633f;
  FUN_23e8bba40(plVar15,&DAT_23ec5b14b,plVar13,plVar1);
  if (_DAT_23eeb02f8 == plVar15) {
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c6590;
      (**(code **)(plVar15[1] + 0x30))(plVar15);
    }
    _DAT_23eeb02f8 = (longlong *)0x0;
  }
  lVar10 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar7 = *(longlong **)(lVar10 + 0x28);
  plVar15 = (longlong *)plVar7[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar10 + 0x30);
  *(undefined4 *)(plVar7 + 8) = 0xffffffff;
  if (plVar15 != (longlong *)0x0) {
    plVar7[2] = 0;
    *plVar15 = *plVar15 + -1;
    if (*plVar15 == 0) {
      puStack_b0 = (undefined8 *)0x23e2c6385;
      (**(code **)(plVar15[1] + 0x30))();
    }
  }
  *plVar7 = *plVar7 + -1;
  if (*plVar7 == 0) {
    puStack_b0 = (undefined8 *)0x23e2c6395;
    (**(code **)(plVar7[1] + 0x30))(plVar7);
  }
  plVar7[0xf] = 0;
  *plVar13 = *plVar13 + -1;
  if (*plVar13 == 0) {
    puStack_b0 = (undefined8 *)0x23e2c63af;
    (**(code **)(plVar13[1] + 0x30))(plVar13);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    puStack_b0 = (undefined8 *)0x23e2c63c0;
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  puStack_b0 = (undefined8 *)0x23e2c63d3;
  FUN_23a33aa70(param_1,plVar8,pcStack_88,pcVar18);
  return (code *)0x0;
}
