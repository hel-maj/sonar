/* ===== 23c62b1b0 license.license_client:158 ===== */
/* ghidra_name=FUN_23c62b1b0 entry=23c62b1b0 size=8626 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* WARNING: Restarted to delay deadcode elimination for space: ram */

code * FUN_23c62b1b0(longlong param_1,undefined8 param_2,undefined8 *param_3)

{
  longlong *plVar1;
  longlong lVar2;
  longlong *plVar3;
  undefined8 *puVar4;
  undefined8 uVar5;
  code *pcVar6;
  int iVar7;
  longlong *plVar8;
  longlong *plVar9;
  longlong *plVar10;
  longlong lVar11;
  longlong *plVar12;
  code *pcVar13;
  code *pcVar14;
  code *pcVar15;
  longlong *plVar16;
  code *pcVar17;
  longlong *plVar18;
  longlong *plVar19;
  code *pcVar20;
  undefined4 uVar21;
  code *pcStack_e8;
  code *pcStack_e0;
  code *pcStack_d8;
  longlong *plStack_a8;
  undefined8 uStack_a0;
  undefined1 auStack_98 [16];
  code *apcStack_88 [2];
  longlong *plStack_78;
  code *pcStack_70;
  code *pcStack_68;
  
  plVar8 = _DAT_23ee29ca0;
  plVar1 = (longlong *)*param_3;
  if (_DAT_23ee29ca0 == (longlong *)0x0) {
LAB_23c62b1f5:
    _DAT_23ee29ca0 = (longlong *)FUN_23e91f3b0(param_1,_DAT_23ee29c98,DAT_23ee29d18);
  }
  else {
    lVar11 = *_DAT_23ee29ca0;
    if (1 < lVar11) {
      *_DAT_23ee29ca0 = lVar11 + -1;
      goto LAB_23c62b1f5;
    }
    if (_DAT_23ee29ca0[2] != 0) {
      *_DAT_23ee29ca0 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      goto LAB_23c62b1f5;
    }
  }
  plVar3 = _DAT_23ee29ca0;
  lVar11 = *(longlong *)(param_1 + 0x38);
  plVar8 = _DAT_23ee29ca0 + 9;
  lVar2 = *(longlong *)(lVar11 + 8);
  _DAT_23ee29ca0[0xf] = lVar2;
  *(longlong **)(lVar11 + 8) = plVar8;
  if ((lVar2 != 0) &&
     (((*(char *)(lVar2 + 0x45) == '\x01' ||
       ((ulonglong)
        (*(longlong *)(lVar2 + 0x20) + 0xb8 +
        (longlong)*(int *)(*(longlong *)(lVar2 + 0x20) + 0xa8) * 2) <= *(ulonglong *)(lVar2 + 0x38))
       ) && (plVar3[0xe] != 0)))) {
    plVar8 = *(longlong **)(lVar2 + 0x28);
    *(longlong **)(plVar3[0xe] + 0x10) = plVar8;
    if (plVar8 != (longlong *)0x0) {
      *plVar8 = *plVar8 + 1;
    }
  }
  *plVar3 = *plVar3 + 1;
  uVar5 = DAT_23ee283a8;
  *(undefined4 *)(plVar3 + 8) = 0;
  plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,uVar5);
  if (plVar8 == (longlong *)0x0) {
    pcStack_d8 = *(code **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_e8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    if (pcVar20 == (code *)0x0) {
      pcVar15 = (code *)0x0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      iVar7 = 0xa0;
      pcStack_e0 = _PyRuntime_exref;
      plVar8 = (longlong *)0x0;
      goto LAB_23c62bed5;
    }
    plVar8 = (longlong *)0x0;
    if (*(longlong **)(pcVar20 + 0x18) == plVar3) goto LAB_23c62b7a0;
    pcVar15 = (code *)0x0;
    pcVar14 = (code *)0x0;
    pcVar13 = (code *)0x0;
    plVar9 = (longlong *)0x0;
    uVar21 = 0xa0;
    pcStack_e0 = _PyRuntime_exref;
    plVar8 = (longlong *)0x0;
  }
  else {
    iVar7 = FUN_23a35f020(plVar8);
    *plVar8 = *plVar8 + -1;
    if (*plVar8 == 0) {
      (**(code **)(plVar8[1] + 0x30))(plVar8);
    }
    pcVar20 = _Py_FalseStruct_exref;
    if (iVar7 == -1) {
      pcStack_d8 = *(code **)(param_1 + 0x60);
      pcVar20 = *(code **)(param_1 + 0x70);
      *(undefined8 *)(param_1 + 0x70) = 0;
      pcStack_e8 = *(code **)(param_1 + 0x68);
      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
      if (pcVar20 == (code *)0x0) {
        pcVar15 = (code *)0x0;
        pcVar14 = (code *)0x0;
        pcVar13 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        iVar7 = 0xa0;
        pcStack_e0 = _PyRuntime_exref;
        goto LAB_23c62bed5;
      }
      if (plVar3 == *(longlong **)(pcVar20 + 0x18)) {
        pcVar15 = (code *)0x0;
        pcVar14 = (code *)0x0;
        pcVar13 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        pcVar17 = pcVar20;
        goto LAB_23c62b5e0;
      }
      pcVar15 = (code *)0x0;
      pcVar14 = (code *)0x0;
      pcVar13 = (code *)0x0;
      plVar9 = (longlong *)0x0;
      plVar8 = (longlong *)0x0;
      uVar21 = 0xa0;
      pcStack_e0 = _PyRuntime_exref;
    }
    else {
      if (iVar7 == 0) {
        pcVar15 = (code *)0x0;
        pcVar14 = (code *)0x0;
        pcVar13 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
        goto LAB_23c62b2d4;
      }
      plVar8 = (longlong *)FUN_23e8bc2f0(plVar1,DAT_23ee283a8);
      if (plVar8 == (longlong *)0x0) {
        pcStack_d8 = *(code **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_e8 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        plVar8 = (longlong *)0x0;
        if (pcVar20 == (code *)0x0) {
LAB_23c62c760:
          pcVar15 = (code *)0x0;
          pcVar14 = (code *)0x0;
          pcVar13 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          iVar7 = 0xa3;
          pcStack_e0 = _PyRuntime_exref;
          goto LAB_23c62bed5;
        }
        plVar8 = (longlong *)0x0;
        plVar9 = (longlong *)0x0;
        if (plVar3 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23c62b7a0;
LAB_23c62be49:
        plVar8 = plVar9;
        pcVar15 = (code *)0x0;
        pcVar14 = (code *)0x0;
        pcVar13 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        uVar21 = 0xa3;
        pcStack_e0 = _PyRuntime_exref;
      }
      else {
        plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,DAT_23ed6ce40);
        *plVar8 = *plVar8 + -1;
        if (*plVar8 == 0) {
          (**(code **)(plVar8[1] + 0x30))(plVar8);
        }
        if (plVar9 != (longlong *)0x0) {
          *(undefined4 *)(plVar3 + 5) = 0xa3;
          plVar8 = (longlong *)FUN_23e94bb80(param_1,plVar9,DAT_23ee28578);
          *plVar9 = *plVar9 + -1;
          if (*plVar9 == 0) {
            (**(code **)(plVar9[1] + 0x30))(plVar9);
          }
          if (plVar8 == (longlong *)0x0) {
            pcStack_d8 = *(code **)(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_e8 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcVar20 == (code *)0x0) goto LAB_23c62c760;
            plVar9 = plVar8;
            if (*(longlong **)(pcVar20 + 0x18) != plVar3) goto LAB_23c62be49;
          }
          else {
            iVar7 = FUN_23a35f020(plVar8);
            pcVar20 = _Py_FalseStruct_exref;
            if (iVar7 != -1) {
              if (iVar7 == 0) {
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                pcVar13 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
                goto LAB_23c62b2d4;
              }
              plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23ee285d8);
              pcStack_d8 = _Py_NoneStruct_exref;
              if (plVar9 == (longlong *)0x0) {
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                pcVar13 = (code *)0x0;
                pcVar20 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                uVar21 = 0xa9;
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar17 = *(code **)(param_1 + 0x68);
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                plVar9 = (longlong *)0x0;
                goto LAB_23c62c02c;
              }
              *(undefined4 *)(plVar3 + 5) = 0xa9;
              plVar10 = (longlong *)FUN_23e94bb80(param_1,plVar9,_DAT_23ee285e0);
              *plVar9 = *plVar9 + -1;
              if (*plVar9 == 0) {
                (**(code **)(plVar9[1] + 0x30))(plVar9);
              }
              pcStack_d8 = _Py_NoneStruct_exref;
              if (plVar10 == (longlong *)0x0) {
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                plVar9 = (longlong *)0x0;
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar17 = *(code **)(param_1 + 0x68);
                pcVar20 = *(code **)(param_1 + 0x70);
                uVar21 = 0xa9;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar13 = (code *)0x0;
                goto LAB_23c62c02c;
              }
              iVar7 = FUN_23a35f020(plVar10);
              lVar11 = *plVar10 + -1;
              if (iVar7 == -1) {
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar17 = *(code **)(param_1 + 0x68);
                pcVar20 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = lVar11;
                if (lVar11 == 0) {
                  pcVar15 = (code *)0x0;
                  pcVar14 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                  (**(code **)(plVar10[1] + 0x30))(plVar10);
                  plVar9 = (longlong *)0x0;
                  uVar21 = 0xa9;
                  pcStack_d8 = _Py_NoneStruct_exref;
                }
                else {
                  pcVar15 = (code *)0x0;
                  pcVar14 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                  uVar21 = 0xa9;
                  plVar9 = (longlong *)0x0;
                  pcStack_d8 = _Py_NoneStruct_exref;
                }
                goto LAB_23c62c02c;
              }
              *plVar10 = lVar11;
              if (lVar11 == 0) {
                (**(code **)(plVar10[1] + 0x30))(plVar10);
              }
              if (iVar7 != 0) {
                lVar11 = FUN_23ead5df0();
                if (lVar11 == 0) {
                  pcVar15 = (code *)0x0;
                  pcVar14 = (code *)0x0;
                  pcVar13 = (code *)0x0;
                  FUN_23e915740(param_1,&plStack_78,_DAT_23ee28458);
                  uVar21 = 0xaa;
                  pcStack_d8 = _Py_NoneStruct_exref;
                  plVar9 = (longlong *)0x0;
                  pcVar20 = pcStack_68;
                  plVar12 = plStack_78;
                  pcVar17 = pcStack_70;
                  goto LAB_23c62c02c;
                }
                plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23ee285e8);
                pcStack_d8 = _Py_NoneStruct_exref;
                if (plVar10 == (longlong *)0x0) {
                  pcVar15 = (code *)0x0;
                  pcVar14 = (code *)0x0;
                  plVar9 = (longlong *)0x0;
                  plVar12 = *(longlong **)(param_1 + 0x60);
                  pcVar20 = *(code **)(param_1 + 0x70);
                  uVar21 = 0xaa;
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  pcVar13 = (code *)0x0;
                  pcVar17 = *(code **)(param_1 + 0x68);
                  goto LAB_23c62c02c;
                }
                plVar9 = (longlong *)FUN_23e8bc2f0(plVar8,_DAT_23ee285f0);
                if (plVar9 == (longlong *)0x0) {
                  plVar12 = *(longlong **)(param_1 + 0x60);
                  pcVar17 = *(code **)(param_1 + 0x68);
                  pcVar20 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  *plVar10 = *plVar10 + -1;
                  plVar9 = (longlong *)0x0;
                  if (*plVar10 == 0) {
                    pcVar15 = (code *)0x0;
                    pcVar14 = (code *)0x0;
                    pcVar13 = (code *)0x0;
                    FUN_23a334bc0(plVar10);
                    uVar21 = 0xaa;
                    pcStack_d8 = _Py_NoneStruct_exref;
                    goto LAB_23c62c02c;
                  }
                }
                else {
                  *(undefined4 *)(plVar3 + 5) = 0xaa;
                  plVar12 = (longlong *)FUN_23e9557e0(param_1,plVar9,_DAT_23ee285f8);
                  *plVar9 = *plVar9 + -1;
                  if (*plVar9 == 0) {
                    (**(code **)(plVar9[1] + 0x30))(plVar9);
                  }
                  if (plVar12 == (longlong *)0x0) {
                    plVar12 = *(longlong **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x68);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *plVar10 = *plVar10 + -1;
                    pcVar14 = (code *)0x0;
                    if (*plVar10 == 0) {
                      pcVar15 = (code *)0x0;
                      pcVar13 = (code *)0x0;
                      FUN_23a334bc0(plVar10);
                      plVar9 = (longlong *)0x0;
                      uVar21 = 0xaa;
                      pcStack_d8 = _Py_NoneStruct_exref;
                    }
                    else {
                      pcVar15 = (code *)0x0;
                      pcVar13 = (code *)0x0;
                      plVar9 = (longlong *)0x0;
                      uVar21 = 0xaa;
                      pcStack_d8 = _Py_NoneStruct_exref;
                    }
                    goto LAB_23c62c02c;
                  }
                  *(undefined4 *)(plVar3 + 5) = 0xaa;
                  plVar9 = (longlong *)FUN_23e914090(param_1,plVar10,plVar12);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (plVar9 != (longlong *)0x0) goto LAB_23c62ba0b;
                  pcVar20 = *(code **)(param_1 + 0x70);
                  plVar12 = *(longlong **)(param_1 + 0x60);
                  pcVar17 = *(code **)(param_1 + 0x68);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                }
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                pcVar13 = (code *)0x0;
                uVar21 = 0xaa;
                pcStack_d8 = _Py_NoneStruct_exref;
                goto LAB_23c62c02c;
              }
              lVar11 = FUN_23ead5df0();
              if (lVar11 == 0) {
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                pcVar13 = (code *)0x0;
                FUN_23e915740(param_1,&plStack_78,_DAT_23ee28458);
                uVar21 = 0xac;
                pcStack_d8 = _Py_NoneStruct_exref;
                plVar9 = (longlong *)0x0;
                pcVar20 = pcStack_68;
                plVar12 = plStack_78;
                pcVar17 = pcStack_70;
                goto LAB_23c62c02c;
              }
              *(undefined4 *)(plVar3 + 5) = 0xac;
              plVar9 = (longlong *)FUN_23e915840(param_1,lVar11,_DAT_23ee285e8);
              pcStack_d8 = _Py_NoneStruct_exref;
              if (plVar9 == (longlong *)0x0) {
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                pcVar13 = (code *)0x0;
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x70);
                uVar21 = 0xac;
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar17 = *(code **)(param_1 + 0x68);
                goto LAB_23c62c02c;
              }
LAB_23c62ba0b:
              lVar11 = FUN_23ead5df0();
              if (lVar11 == 0) {
                pcVar15 = (code *)0x0;
                pcVar14 = (code *)0x0;
                FUN_23e915740(param_1,&plStack_78,_DAT_23ee28458);
                uVar21 = 0xaf;
                pcStack_d8 = _Py_NoneStruct_exref;
                pcVar13 = (code *)0x0;
                pcVar20 = pcStack_68;
                plVar12 = plStack_78;
                pcVar17 = pcStack_70;
                goto LAB_23c62c02c;
              }
              plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23ee28460);
              pcStack_d8 = _Py_NoneStruct_exref;
              if (plVar10 == (longlong *)0x0) {
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x70);
                pcVar15 = (code *)0x0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar14 = (code *)0x0;
                uVar21 = 0xaf;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar13 = (code *)0x0;
                pcVar17 = *(code **)(param_1 + 0x68);
                goto LAB_23c62c02c;
              }
              lVar11 = FUN_23ead5ca0();
              if (lVar11 == 0) {
                FUN_23e915740(param_1,&plStack_78,_DAT_23ee28468);
                *plVar10 = *plVar10 + -1;
                lVar11 = *plVar10;
                plVar12 = plStack_78;
                pcVar17 = pcStack_70;
                pcVar20 = pcStack_68;
              }
              else {
                plVar12 = (longlong *)FUN_23e8bc2f0(lVar11,_DAT_23ee28470);
                if (plVar12 != (longlong *)0x0) {
                  *(undefined4 *)(plVar3 + 5) = 0xaf;
                  pcVar13 = (code *)FUN_23e914090(param_1,plVar10,plVar12);
                  *plVar10 = *plVar10 + -1;
                  if (*plVar10 == 0) {
                    (**(code **)(plVar10[1] + 0x30))(plVar10);
                  }
                  *plVar12 = *plVar12 + -1;
                  if (*plVar12 == 0) {
                    (**(code **)(plVar12[1] + 0x30))(plVar12);
                  }
                  if (pcVar13 == (code *)0x0) {
                    pcVar20 = *(code **)(param_1 + 0x70);
                    plVar12 = *(longlong **)(param_1 + 0x60);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    pcStack_d8 = _Py_NoneStruct_exref;
                    pcVar15 = (code *)0x0;
                    pcVar14 = (code *)0x0;
                    pcVar13 = (code *)0x0;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    uVar21 = 0xaf;
                    pcVar17 = *(code **)(param_1 + 0x68);
                    goto LAB_23c62c02c;
                  }
                  pcVar14 = (code *)FUN_23e8bc2f0(plVar9,_DAT_23ee28600);
                  plVar12 = plVar9;
                  pcStack_e8 = pcVar13;
                  if (pcVar14 == (code *)0x0) goto LAB_23c62d23d;
                  *(longlong *)pcVar14 = *(longlong *)pcVar14 + -1;
                  if (*(longlong *)pcVar14 == 0) {
                    FUN_23a334bc0(pcVar14);
                  }
                  pcStack_d8 = _Py_NoneStruct_exref;
                  if (pcVar14 == _Py_NoneStruct_exref) {
                    plVar12 = (longlong *)FUN_23e8bc2f0(pcVar13,_DAT_23ee285f0);
                    lVar11 = _DAT_23ee28608;
                    if (plVar12 == (longlong *)0x0) {
                      plVar12 = *(longlong **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar14 = (code *)0x0;
                      uVar21 = 0xb3;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar15 = (code *)0x0;
                      pcVar17 = *(code **)(param_1 + 0x68);
                      goto LAB_23c62c02c;
                    }
                    *(undefined4 *)(plVar3 + 5) = 0xb3;
                    pcVar14 = (code *)FUN_23e9186b0(param_1,plVar12,lVar11 + 0x18,_DAT_23ee28610);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    if (pcVar14 == (code *)0x0) {
                      plVar12 = *(longlong **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar21 = 0xb3;
                      pcVar15 = (code *)0x0;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar17 = *(code **)(param_1 + 0x68);
                      goto LAB_23c62c02c;
                    }
                    pcVar15 = (code *)FUN_23e8d09c0(pcVar14,plVar9);
                    if (pcVar15 == (code *)0x0) {
                      plVar12 = *(longlong **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      uVar21 = 0xb4;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar17 = *(code **)(param_1 + 0x68);
                      goto LAB_23c62c02c;
                    }
                  }
                  else {
                    pcVar15 = (code *)FUN_23e8d09c0(pcVar13,plVar9);
                    if (pcVar15 == (code *)0x0) {
                      plVar12 = *(longlong **)(param_1 + 0x60);
                      pcVar20 = *(code **)(param_1 + 0x70);
                      *(undefined8 *)(param_1 + 0x70) = 0;
                      pcVar14 = (code *)0x0;
                      uVar21 = 0xb6;
                      *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                      pcVar17 = *(code **)(param_1 + 0x68);
                      goto LAB_23c62c02c;
                    }
                    pcVar14 = (code *)0x0;
                  }
                  lVar11 = FUN_23ead5f40();
                  if (lVar11 == 0) {
                    FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
                    uVar21 = 0xb8;
                    pcVar20 = pcStack_68;
                    plVar12 = plStack_78;
                    pcVar17 = pcStack_70;
                    goto LAB_23c62c02c;
                  }
                  plVar10 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23ee28400);
                  plVar12 = _DAT_23ee28618;
                  if (plVar10 == (longlong *)0x0) {
LAB_23c62d284:
                    plVar12 = *(longlong **)(param_1 + 0x60);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    uVar21 = 0xb8;
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    pcVar17 = *(code **)(param_1 + 0x68);
                    goto LAB_23c62c02c;
                  }
                  plVar16 = (longlong *)FUN_23e916ad0(*(undefined8 *)(param_1 + 0x10),6);
                  *plVar12 = *plVar12 + 1;
                  plVar16[3] = (longlong)plVar12;
                  *(undefined4 *)(plVar3 + 5) = 0xb8;
                  plVar12 = (longlong *)FUN_23e91bfe0(param_1,pcVar13);
                  if (plVar12 == (longlong *)0x0) {
LAB_23c62d0fc:
                    plVar12 = *(longlong **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x68);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar10 = *plVar10 + -1;
                    if (*plVar10 == 0) {
                      FUN_23a334bc0(plVar10);
                    }
                    *plVar16 = *plVar16 + -1;
                    lVar11 = *plVar16;
                    plVar10 = plVar16;
                  }
                  else {
                    lVar11 = FUN_23e94f9d0(param_1);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    if (lVar11 == 0) goto LAB_23c62d0fc;
                    plVar16[4] = lVar11;
                    plVar12 = _DAT_23ee28620;
                    *_DAT_23ee28620 = *_DAT_23ee28620 + 1;
                    plVar16[5] = (longlong)plVar12;
                    *(undefined4 *)(plVar3 + 5) = 0xb8;
                    plVar12 = (longlong *)FUN_23e91bfe0(param_1,plVar9);
                    if (plVar12 == (longlong *)0x0) goto LAB_23c62d0fc;
                    lVar11 = FUN_23e94f9d0(param_1);
                    *plVar12 = *plVar12 + -1;
                    if (*plVar12 == 0) {
                      FUN_23a334bc0(plVar12);
                    }
                    if (lVar11 == 0) goto LAB_23c62d0fc;
                    plVar16[6] = lVar11;
                    plVar12 = _DAT_23ee28628;
                    *_DAT_23ee28628 = *_DAT_23ee28628 + 1;
                    plVar16[7] = (longlong)plVar12;
                    lVar11 = FUN_23e94f9d0(param_1,pcVar15);
                    if (lVar11 == 0) goto LAB_23c62d0fc;
                    plVar16[8] = lVar11;
                    plVar12 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar16);
                    *plVar16 = *plVar16 + -1;
                    if (*plVar16 == 0) {
                      FUN_23a334bc0();
                    }
                    if (plVar12 != (longlong *)0x0) {
                      *(undefined4 *)(plVar3 + 5) = 0xb8;
                      plVar16 = (longlong *)FUN_23e914090(param_1,plVar10);
                      *plVar10 = *plVar10 + -1;
                      if (*plVar10 == 0) {
                        FUN_23a334bc0(plVar10);
                      }
                      *plVar12 = *plVar12 + -1;
                      if (*plVar12 == 0) {
                        FUN_23a334bc0(plVar12);
                      }
                      if (plVar16 == (longlong *)0x0) goto LAB_23c62d284;
                      *plVar16 = *plVar16 + -1;
                      if (*plVar16 == 0) {
                        FUN_23a334bc0(plVar16);
                      }
                      FUN_23ebf6b20(*(undefined8 *)(param_1 + 0x38));
                      *(longlong *)pcVar15 = *(longlong *)pcVar15 + 1;
                      *plVar8 = *plVar8 + -1;
                      pcVar20 = pcVar15;
                      if (*plVar8 == 0) {
                        (**(code **)(plVar8[1] + 0x30))(plVar8);
                        goto LAB_23c62b35d;
                      }
                      *plVar9 = *plVar9 + -1;
                      if (*plVar9 == 0) goto LAB_23c62b363;
                      goto LAB_23c62b372;
                    }
                    plVar12 = *(longlong **)(param_1 + 0x60);
                    pcVar17 = *(code **)(param_1 + 0x68);
                    pcVar20 = *(code **)(param_1 + 0x70);
                    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                    *(undefined8 *)(param_1 + 0x70) = 0;
                    *plVar10 = *plVar10 + -1;
                    lVar11 = *plVar10;
                  }
                  if (lVar11 == 0) {
                    FUN_23a334bc0(plVar10);
                    uVar21 = 0xb8;
                  }
                  else {
                    uVar21 = 0xb8;
                  }
                  goto LAB_23c62c02c;
                }
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar17 = *(code **)(param_1 + 0x68);
                pcVar20 = *(code **)(param_1 + 0x70);
                *(undefined8 *)(param_1 + 0x70) = 0;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                *plVar10 = *plVar10 + -1;
                lVar11 = *plVar10;
              }
              pcVar14 = (code *)0x0;
              if (lVar11 == 0) {
                pcVar15 = (code *)0x0;
                pcVar13 = (code *)0x0;
                FUN_23a334bc0(plVar10);
                uVar21 = 0xaf;
                pcStack_d8 = _Py_NoneStruct_exref;
              }
              else {
                pcVar14 = (code *)0x0;
                pcVar15 = (code *)0x0;
                pcVar13 = (code *)0x0;
                uVar21 = 0xaf;
                pcStack_d8 = _Py_NoneStruct_exref;
              }
LAB_23c62c02c:
              do {
                plVar10 = *(longlong **)(param_1 + 0x138);
                auStack_98._8_8_ = pcVar17;
                auStack_98._0_8_ = plVar12;
                if (plVar10 != (longlong *)0x0) {
                  *plVar10 = *plVar10 + 1;
                }
                pcVar17 = DAT_23ed6a4f8;
                apcStack_88[0] = pcVar20;
                if (pcVar20 == (code *)0x0) {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar20 = *(code **)DAT_23ed6a4f8;
                    *(undefined8 *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar20;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcStack_e0 = _PyRuntime_exref;
                  *(longlong *)(pcVar17 + 0x10) = 0;
                  *(longlong **)(pcVar17 + 0x18) = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar11 = *(longlong *)(pcStack_e0 + 0x1f8);
                  *(undefined4 *)(pcVar17 + 0x24) = uVar21;
                  lVar11 = *(longlong *)(lVar11 + 0x10);
                  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
                  lVar11 = *(longlong *)(lVar11 + 0x2e8);
                  lVar2 = *(longlong *)(pcVar17 + -8);
                  plVar12 = *(longlong **)(lVar11 + 8);
                  *plVar12 = (longlong)(pcVar17 + -0x10);
                  *(longlong *)(pcVar17 + -0x10) = lVar11;
                  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar12;
                  *(code **)(lVar11 + 8) = pcVar17 + -0x10;
                  if ((apcStack_88[0] != (code *)0x0) &&
                     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                     *(longlong *)apcStack_88[0] == 0)) {
                    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))(apcStack_88[0]);
                  }
                }
                else {
                  if (DAT_23ed6a4f8 == (code *)0x0) {
                    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
                  }
                  else {
                    pcVar6 = *(code **)DAT_23ed6a4f8;
                    *(undefined8 *)DAT_23ed6a4f8 = 1;
                    DAT_23ed6a4f8 = pcVar6;
                    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
                  }
                  pcStack_e0 = _PyRuntime_exref;
                  *(longlong **)(pcVar17 + 0x18) = plVar3;
                  *plVar3 = *plVar3 + 1;
                  lVar11 = *(longlong *)(pcStack_e0 + 0x1f8);
                  *(undefined4 *)(pcVar17 + 0x24) = uVar21;
                  lVar11 = *(longlong *)(lVar11 + 0x10);
                  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
                  lVar11 = *(longlong *)(lVar11 + 0x2e8);
                  plVar12 = *(longlong **)(lVar11 + 8);
                  *plVar12 = (longlong)(pcVar17 + -0x10);
                  *(longlong *)(pcVar17 + -0x10) = lVar11;
                  *(ulonglong *)(pcVar17 + -8) =
                       (ulonglong)plVar12 | (ulonglong)((uint)*(longlong *)(pcVar17 + -8) & 3);
                  *(code **)(lVar11 + 8) = pcVar17 + -0x10;
                  *(code **)(pcVar17 + 0x10) = pcVar20;
                  *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                  if ((apcStack_88[0] != (code *)0x0) &&
                     (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                     *(longlong *)apcStack_88[0] == 0)) {
                    (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
                  }
                }
                apcStack_88[0] = pcVar17;
                if (((code *)auStack_98._0_8_ != pcStack_d8) &&
                   ((code *)auStack_98._0_8_ != (code *)0x0)) {
                  FUN_23e91b1b0(param_1,auStack_98,auStack_98 + 8,apcStack_88);
                }
                plVar12 = *(longlong **)(auStack_98._8_8_ + 0x28);
                if (apcStack_88[0] == pcStack_d8) {
                  pcVar20 = (code *)0x0;
                }
                else {
                  pcVar20 = apcStack_88[0];
                  if (apcStack_88[0] != (code *)0x0) {
                    *(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + 1;
                  }
                }
                *(code **)(auStack_98._8_8_ + 0x28) = pcVar20;
                if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                  (**(code **)(plVar12[1] + 0x30))();
                }
                plVar12 = *(longlong **)(param_1 + 0x138);
                *(undefined8 *)(param_1 + 0x138) = auStack_98._8_8_;
                if ((plVar12 != (longlong *)0x0) && (*plVar12 = *plVar12 + -1, *plVar12 == 0)) {
                  (**(code **)(plVar12[1] + 0x30))();
                }
                *(longlong *)auStack_98._0_8_ = *(longlong *)auStack_98._0_8_ + -1;
                if (*(longlong *)auStack_98._0_8_ == 0) {
                  (**(code **)(*(longlong *)(auStack_98._0_8_ + 8) + 0x30))();
                }
                if ((apcStack_88[0] != (code *)0x0) &&
                   (*(longlong *)apcStack_88[0] = *(longlong *)apcStack_88[0] + -1,
                   *(longlong *)apcStack_88[0] == 0)) {
                  (**(code **)(*(longlong *)(apcStack_88[0] + 8) + 0x30))();
                }
                apcStack_88[0] = (code *)0x0;
                auStack_98 = (undefined1  [16])0x0;
                iVar7 = FUN_23a35ebd0(param_1,*(undefined8 *)(*(longlong *)(param_1 + 0x138) + 8),
                                      *(undefined8 *)PyExc_Exception_exref);
                if (iVar7 == 0) {
                  pcStack_e8 = *(code **)(param_1 + 0x138);
                  if ((pcStack_e8 == pcStack_d8) || (pcStack_e8 == (code *)0x0)) {
                    pcStack_d8 = *(code **)PyExc_RuntimeError_exref;
                    pcVar20 = (code *)PyUnicode_FromString("No active exception to reraise");
                    *(longlong *)pcStack_d8 = *(longlong *)pcStack_d8 + 1;
                    pcStack_e8 = *(code **)(param_1 + 0x138);
                    *(longlong **)(param_1 + 0x138) = plVar10;
                    if ((pcStack_e8 == (code *)0x0) ||
                       (lVar11 = *(longlong *)pcStack_e8, *(longlong *)pcStack_e8 = lVar11 + -1,
                       lVar11 + -1 != 0)) {
                      iVar7 = 0xa7;
                      pcStack_e8 = pcVar20;
                      goto LAB_23c62bed5;
                    }
                    iVar7 = 0xa7;
LAB_23c62cc1d:
                    (**(code **)(*(longlong *)(pcStack_e8 + 8) + 0x30))();
                    pcStack_e8 = pcVar20;
                    if (iVar7 != 0) goto LAB_23c62bed5;
                  }
                  else {
                    pcStack_d8 = *(code **)(pcStack_e8 + 8);
                    pcVar20 = *(code **)(pcStack_e8 + 0x28);
                    *(longlong *)pcStack_e8 = *(longlong *)pcStack_e8 + 1;
                    *(longlong *)pcStack_d8 = *(longlong *)pcStack_d8 + 1;
                    if (pcVar20 != (code *)0x0) {
                      *(longlong *)pcVar20 = *(longlong *)pcVar20 + 1;
                      if (*(longlong **)(pcVar20 + 0x18) == plVar3) {
                        *(undefined4 *)(plVar3 + 5) = *(undefined4 *)(pcVar20 + 0x24);
                      }
                      *(longlong **)(param_1 + 0x138) = plVar10;
                      lVar11 = *(longlong *)pcStack_e8;
                      *(longlong *)pcStack_e8 = lVar11 + -1;
                      if (lVar11 + -1 == 0) {
                        (**(code **)((longlong)pcStack_d8 + 0x30))();
                        iVar7 = 0;
                        goto LAB_23c62c6fc;
                      }
                      pcVar17 = pcVar20;
                      if (plVar3 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23c62b5e0;
                      goto LAB_23c62c70f;
                    }
                    *(longlong **)(param_1 + 0x138) = plVar10;
                    lVar11 = *(longlong *)pcStack_e8;
                    *(longlong *)pcStack_e8 = lVar11 + -1;
                    if (lVar11 + -1 == 0) {
                      iVar7 = 0;
                      pcVar20 = pcStack_e8;
                      goto LAB_23c62cc1d;
                    }
                  }
                  iVar7 = (int)plVar3[5];
                  goto LAB_23c62bed5;
                }
                plVar12 = *(longlong **)(param_1 + 0x138);
                *plVar12 = *plVar12 + 1;
                lVar11 = FUN_23ead5f40();
                if (lVar11 == 0) {
                  FUN_23e915740(param_1,&plStack_78,DAT_23ee283f8);
                  pcStack_d8 = (code *)plStack_78;
                  pcStack_e8 = pcStack_70;
                  pcVar20 = pcStack_68;
                  goto LAB_23c62c930;
                }
                plVar18 = (longlong *)FUN_23e8bc2f0(lVar11,DAT_23ee284c0);
                plVar16 = _DAT_23ee28630;
                if (plVar18 == (longlong *)0x0) {
                  pcStack_d8 = *(code **)(param_1 + 0x60);
                  pcVar20 = *(code **)(param_1 + 0x70);
                  *(undefined8 *)(param_1 + 0x70) = 0;
                  pcStack_e8 = *(code **)(param_1 + 0x68);
                  *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                  goto LAB_23c62c930;
                }
                lVar11 = *(longlong *)(param_1 + 0x10);
                plVar19 = *(longlong **)(lVar11 + 0xe20);
                if (plVar19 == (longlong *)0x0) {
                  plVar19 = (longlong *)FUN_23e916a20(PyTuple_Type_exref,2);
                }
                else {
                  lVar2 = plVar19[3];
                  *(int *)(lVar11 + 0xebc) = *(int *)(lVar11 + 0xebc) + -1;
                  *(longlong *)(lVar11 + 0xe20) = lVar2;
                  *plVar19 = 1;
                }
                plVar19[4] = 0;
                lVar11 = *(longlong *)
                          (*(longlong *)(*(longlong *)(pcStack_e0 + 0x1f8) + 0x10) + 0x2e8);
                lVar2 = plVar19[-1];
                puVar4 = *(undefined8 **)(lVar11 + 8);
                *puVar4 = plVar19 + -2;
                plVar19[-2] = lVar11;
                plVar19[-1] = (ulonglong)((uint)lVar2 & 3) | (ulonglong)puVar4;
                *(longlong **)(lVar11 + 8) = plVar19 + -2;
                *plVar16 = *plVar16 + 1;
                plVar19[3] = (longlong)plVar16;
                uVar5 = DAT_23ed6cd28;
                if (DAT_23ed6a4c0 != (longlong *)0x0) goto LAB_23c62c3ab;
                plVar16 = (longlong *)PyDict_GetItemString(DAT_23ed6ccc0,"format");
                if (plVar16 != (longlong *)0x0) goto code_r0x00023c62cb1f;
                plVar12 = plVar9;
                PyErr_PrintEx(0);
                Py_Exit(1);
                pcStack_e8 = (code *)plVar9;
LAB_23c62d23d:
                plVar9 = plVar12;
                plVar12 = *(longlong **)(param_1 + 0x60);
                pcVar20 = *(code **)(param_1 + 0x70);
                pcStack_d8 = _Py_NoneStruct_exref;
                *(undefined8 *)(param_1 + 0x70) = 0;
                pcVar15 = (code *)0x0;
                uVar21 = 0xb2;
                *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
                pcVar13 = pcStack_e8;
                pcVar17 = *(code **)(param_1 + 0x68);
              } while( true );
            }
            pcStack_d8 = *(code **)(param_1 + 0x60);
            pcVar20 = *(code **)(param_1 + 0x70);
            *(undefined8 *)(param_1 + 0x70) = 0;
            pcStack_e8 = *(code **)(param_1 + 0x68);
            *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
            if (pcVar20 == (code *)0x0) {
              pcStack_e0 = _PyRuntime_exref;
              pcVar15 = (code *)0x0;
              pcVar14 = (code *)0x0;
              pcVar13 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              iVar7 = 0xa4;
              goto LAB_23c62bed5;
            }
            if (plVar3 != *(longlong **)(pcVar20 + 0x18)) {
              pcStack_e0 = _PyRuntime_exref;
              pcVar15 = (code *)0x0;
              pcVar14 = (code *)0x0;
              pcVar13 = (code *)0x0;
              plVar9 = (longlong *)0x0;
              uVar21 = 0xa4;
              goto LAB_23c62b53e;
            }
          }
LAB_23c62b7a0:
          pcVar15 = (code *)0x0;
          pcVar14 = (code *)0x0;
          pcVar13 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          pcVar17 = pcVar20;
          goto LAB_23c62b5e0;
        }
        pcStack_d8 = *(code **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_e8 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        pcVar13 = (code *)0x0;
        if (pcVar20 == (code *)0x0) {
          pcVar15 = (code *)0x0;
          pcVar14 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          iVar7 = 0xa3;
          pcStack_e0 = _PyRuntime_exref;
          goto LAB_23c62bed5;
        }
        if (plVar3 == *(longlong **)(pcVar20 + 0x18)) {
          pcVar15 = (code *)0x0;
          pcVar14 = (code *)0x0;
          plVar9 = (longlong *)0x0;
          plVar8 = (longlong *)0x0;
          pcVar17 = pcVar20;
          goto LAB_23c62b5e0;
        }
        pcVar15 = (code *)0x0;
        pcVar14 = (code *)0x0;
        plVar9 = (longlong *)0x0;
        plVar8 = (longlong *)0x0;
        uVar21 = 0xa3;
        pcStack_e0 = _PyRuntime_exref;
      }
    }
  }
LAB_23c62b53e:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar6 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar6;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong **)(pcVar17 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar11 = *(longlong *)(pcStack_e0 + 0x1f8);
  *(undefined4 *)(pcVar17 + 0x24) = uVar21;
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar11 = *(longlong *)(*(longlong *)(lVar11 + 0x10) + 0x2e8);
  lVar2 = *(longlong *)(pcVar17 + -8);
  plVar12 = *(longlong **)(lVar11 + 8);
  *plVar12 = (longlong)(pcVar17 + -0x10);
  *(longlong *)(pcVar17 + -0x10) = lVar11;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar12;
  lVar2 = *(longlong *)pcVar20;
  *(code **)(lVar11 + 8) = pcVar17 + -0x10;
  *(code **)(pcVar17 + 0x10) = pcVar20;
  if (lVar2 == 0) {
    (**(code **)(*(longlong *)(pcVar20 + 8) + 0x30))(pcVar20);
  }
LAB_23c62b5e0:
  FUN_23e8bba40(plVar3,"ooooooo",plVar1,plVar8,plVar9,pcVar13,pcVar14,pcVar15,0);
  if (_DAT_23ee29ca0 == plVar3) {
    *plVar3 = *plVar3 + -1;
    if (*plVar3 == 0) {
      (**(code **)(plVar3[1] + 0x30))(plVar3);
    }
    _DAT_23ee29ca0 = (longlong *)0x0;
  }
  lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
  plVar3 = *(longlong **)(lVar11 + 0x28);
  plVar12 = (longlong *)plVar3[2];
  *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
  *(undefined4 *)(plVar3 + 8) = 0xffffffff;
  if (plVar12 != (longlong *)0x0) {
    plVar3[2] = 0;
    *plVar12 = *plVar12 + -1;
    if (*plVar12 == 0) {
      (**(code **)(plVar12[1] + 0x30))();
    }
  }
  *plVar3 = *plVar3 + -1;
  if (*plVar3 == 0) {
    (**(code **)(plVar3[1] + 0x30))(plVar3);
  }
  plVar3[0xf] = 0;
  if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
    (**(code **)(plVar8[1] + 0x30))(plVar8);
  }
  if ((plVar9 != (longlong *)0x0) && (*plVar9 = *plVar9 + -1, *plVar9 == 0)) {
    (**(code **)(plVar9[1] + 0x30))(plVar9);
  }
  if ((pcVar13 != (code *)0x0) &&
     (*(longlong *)pcVar13 = *(longlong *)pcVar13 + -1, *(longlong *)pcVar13 == 0)) {
    (**(code **)(*(longlong *)((longlong)pcVar13 + 8) + 0x30))(pcVar13);
  }
  if ((pcVar14 != (code *)0x0) &&
     (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
    (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
  }
  if ((pcVar15 != (code *)0x0) &&
     (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
    (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
  }
  *plVar1 = *plVar1 + -1;
  if (*plVar1 == 0) {
    (**(code **)(plVar1[1] + 0x30))(plVar1);
  }
  FUN_23a33aa70(param_1,pcStack_d8,pcStack_e8,pcVar17);
  return (code *)0x0;
code_r0x00023c62cb1f:
  *plVar16 = *plVar16 + 1;
  DAT_23ed6a4c0 = plVar16;
LAB_23c62c3ab:
  uStack_a0 = uVar5;
  plStack_a8 = plVar12;
  lVar11 = FUN_23e94ed00(param_1,DAT_23ed6a4c0,&plStack_a8);
  if (lVar11 == 0) {
    pcStack_d8 = *(code **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_e8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar11 = *plVar18;
    *plVar18 = lVar11 + -1;
    if (lVar11 + -1 == 0) {
      (**(code **)(plVar18[1] + 0x30))();
    }
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
  }
  else {
    plVar19[4] = lVar11;
    plVar16 = (longlong *)PyUnicode_Join(DAT_23ed6cd28,plVar19);
    *plVar19 = *plVar19 + -1;
    if (*plVar19 == 0) {
      (**(code **)(plVar19[1] + 0x30))(plVar19);
    }
    if (plVar16 != (longlong *)0x0) {
      *(undefined4 *)(plVar3 + 5) = 0xbc;
      plVar19 = (longlong *)FUN_23e914090(param_1,plVar18);
      lVar11 = *plVar18;
      *plVar18 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar18[1] + 0x30))();
      }
      *plVar16 = *plVar16 + -1;
      if (*plVar16 == 0) {
        (**(code **)(plVar16[1] + 0x30))(plVar16);
      }
      if (plVar19 == (longlong *)0x0) {
        pcStack_d8 = *(code **)(param_1 + 0x60);
        pcVar20 = *(code **)(param_1 + 0x70);
        *(undefined8 *)(param_1 + 0x70) = 0;
        pcStack_e8 = *(code **)(param_1 + 0x68);
        *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
        goto LAB_23c62c930;
      }
      *plVar19 = *plVar19 + -1;
      if (*plVar19 == 0) {
        (**(code **)(plVar19[1] + 0x30))(plVar19);
      }
      pcVar20 = _Py_FalseStruct_exref;
      *(longlong *)_Py_FalseStruct_exref = *(longlong *)_Py_FalseStruct_exref + 1;
      lVar11 = *plVar12;
      *plVar12 = lVar11 + -1;
      if (lVar11 + -1 == 0) {
        (**(code **)(plVar12[1] + 0x30))(plVar12);
      }
      plVar3 = *(longlong **)(param_1 + 0x138);
      *(longlong **)(param_1 + 0x138) = plVar10;
      if ((plVar3 != (longlong *)0x0) && (*plVar3 = *plVar3 + -1, *plVar3 == 0)) {
        (**(code **)(plVar3[1] + 0x30))();
      }
LAB_23c62b2d4:
      lVar11 = *(longlong *)(*(longlong *)(param_1 + 0x38) + 8);
      plVar3 = *(longlong **)(lVar11 + 0x28);
      plVar12 = (longlong *)plVar3[2];
      *(undefined8 *)(*(longlong *)(param_1 + 0x38) + 8) = *(undefined8 *)(lVar11 + 0x30);
      *(undefined4 *)(plVar3 + 8) = 0xffffffff;
      if (plVar12 != (longlong *)0x0) {
        plVar3[2] = 0;
        *plVar12 = *plVar12 + -1;
        if (*plVar12 == 0) {
          (**(code **)(plVar12[1] + 0x30))();
        }
      }
      *plVar3 = *plVar3 + -1;
      if (*plVar3 == 0) {
        (**(code **)(plVar3[1] + 0x30))(plVar3);
      }
      plVar3[0xf] = 0;
      if ((plVar8 != (longlong *)0x0) && (*plVar8 = *plVar8 + -1, *plVar8 == 0)) {
        (**(code **)(plVar8[1] + 0x30))(plVar8);
      }
      if (plVar9 != (longlong *)0x0) {
LAB_23c62b35d:
        *plVar9 = *plVar9 + -1;
        if (*plVar9 == 0) {
LAB_23c62b363:
          (**(code **)(plVar9[1] + 0x30))(plVar9);
        }
      }
      if (pcVar13 == (code *)0x0) goto LAB_23c62b382;
LAB_23c62b372:
      *(longlong *)pcVar13 = *(longlong *)pcVar13 + -1;
      if (*(longlong *)pcVar13 == 0) {
        (**(code **)(*(longlong *)((longlong)pcVar13 + 8) + 0x30))(pcVar13);
      }
LAB_23c62b382:
      if ((pcVar14 != (code *)0x0) &&
         (*(longlong *)pcVar14 = *(longlong *)pcVar14 + -1, *(longlong *)pcVar14 == 0)) {
        (**(code **)(*(longlong *)(pcVar14 + 8) + 0x30))(pcVar14);
      }
      if ((pcVar15 != (code *)0x0) &&
         (*(longlong *)pcVar15 = *(longlong *)pcVar15 + -1, *(longlong *)pcVar15 == 0)) {
        (**(code **)(*(longlong *)(pcVar15 + 8) + 0x30))(pcVar15);
      }
      *plVar1 = *plVar1 + -1;
      if (*plVar1 != 0) {
        return pcVar20;
      }
      (**(code **)(plVar1[1] + 0x30))(plVar1);
      return pcVar20;
    }
    pcStack_d8 = *(code **)(param_1 + 0x60);
    pcVar20 = *(code **)(param_1 + 0x70);
    *(undefined8 *)(param_1 + 0x70) = 0;
    pcStack_e8 = *(code **)(param_1 + 0x68);
    *(undefined1 (*) [16])(param_1 + 0x60) = (undefined1  [16])0x0;
    lVar11 = *plVar18;
    *plVar18 = lVar11 + -1;
    if (lVar11 + -1 == 0) {
      (**(code **)(plVar18[1] + 0x30))();
    }
  }
LAB_23c62c930:
  lVar11 = *plVar12;
  *plVar12 = lVar11 + -1;
  if (lVar11 + -1 == 0) {
    (**(code **)(plVar12[1] + 0x30))();
  }
  plVar12 = *(longlong **)(param_1 + 0x138);
  *(longlong **)(param_1 + 0x138) = plVar10;
  if ((plVar12 == (longlong *)0x0) || (*plVar12 = *plVar12 + -1, *plVar12 != 0)) {
    iVar7 = 0xbc;
    if (pcVar20 != (code *)0x0) {
      pcVar17 = pcVar20;
      if (plVar3 == *(longlong **)(pcVar20 + 0x18)) goto LAB_23c62b5e0;
      goto LAB_23c62c9e9;
    }
  }
  else {
    (**(code **)(plVar12[1] + 0x30))();
    if (pcVar20 != (code *)0x0) {
      iVar7 = 0xbc;
LAB_23c62c6fc:
      pcVar17 = pcVar20;
      if (*(longlong **)(pcVar20 + 0x18) == plVar3) goto LAB_23c62b5e0;
      if (iVar7 == 0) {
LAB_23c62c70f:
        uVar21 = (undefined4)plVar3[5];
        goto LAB_23c62b53e;
      }
LAB_23c62c9e9:
      uVar21 = 0xbc;
      goto LAB_23c62b53e;
    }
    iVar7 = 0xbc;
  }
LAB_23c62bed5:
  pcVar17 = DAT_23ed6a4f8;
  if (DAT_23ed6a4f8 == (code *)0x0) {
    pcVar17 = (code *)FUN_23a33a530(PyTraceBack_Type_exref);
  }
  else {
    pcVar20 = *(code **)DAT_23ed6a4f8;
    *(undefined8 *)DAT_23ed6a4f8 = 1;
    DAT_23ed6a4f8 = pcVar20;
    DAT_23ed6a4f0 = DAT_23ed6a4f0 + -1;
  }
  *(longlong *)(pcVar17 + 0x10) = 0;
  *(longlong **)(pcVar17 + 0x18) = plVar3;
  *plVar3 = *plVar3 + 1;
  lVar11 = *(longlong *)(pcStack_e0 + 0x1f8);
  *(int *)(pcVar17 + 0x24) = iVar7;
  lVar11 = *(longlong *)(lVar11 + 0x10);
  *(undefined4 *)(pcVar17 + 0x20) = 0xffffffff;
  lVar11 = *(longlong *)(lVar11 + 0x2e8);
  lVar2 = *(longlong *)(pcVar17 + -8);
  plVar12 = *(longlong **)(lVar11 + 8);
  *plVar12 = (longlong)(pcVar17 + -0x10);
  *(longlong *)(pcVar17 + -0x10) = lVar11;
  *(ulonglong *)(pcVar17 + -8) = (ulonglong)((uint)lVar2 & 3) | (ulonglong)plVar12;
  *(code **)(lVar11 + 8) = pcVar17 + -0x10;
  goto LAB_23c62b5e0;
}
